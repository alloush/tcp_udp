/**
 * holds all c source code for tcp over udp
 */
#include "protocol.h"

struct sockaddr_in name;

/**
 * Creates an endpoint for communication and returns a descriptor. Internally,
 * this is an IPv4 socket over UDP.
 * 
 * @return A -1 is returned if an error occurs, otherwise the return value is a
 *     descriptor referencing the socket.
 */

int SOCKET() {
    return socket(AF_INET, SOCK_DGRAM, 0);
}

/**
 * Assigns a name to an unnamed socket.
 * 
 * @param sock The socket to associate a name with.
 * @return Upon successful completion, a value of 0 is returned. Otherwise, a
 *     value of -1 is returned and the global integer variable errno is set to
 *     indicate the error.
 */

int BIND(int sock, char* host, unsigned short port) {
    int result;
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = INADDR_ANY;
    result = bind(sock, (struct sockaddr *)&name, sizeof(name));
    if (host != NULL) {
        struct hostent *hp = gethostbyname(host);
        if (hp == NULL)
            return -1;
        memcpy(&name.sin_addr, hp->h_addr, hp->h_length);
    }
    return result;
}

/**
 * Accepts a connection on a socket.
 * 
 * @return The call returns -1 on error and the global variable errno is set to
 *     indicate the error. If it succeeds, it returns a non-negative integer
 *     that is a descriptor for the accepted socket.
 */

int ACCEPT(int socket) {
    socklen_t namelen = sizeof(struct sockaddr_in);
    return accept(socket, (struct sockaddr *)&name, &namelen);
}

/**
 * Initiates a connection on a socket.
 * 
 * @return Upon successful completion, a value of 0 is returned. Otherwise, a
 *     value of -1 is returned and the global integer variable errno is set to
 *     indicate the error.
 */

int CONNECT(int socket, char *host, char *service) {
    return 0;
}

/**
 * Sends a message from a socket.
 * 
 * @param socket The socket sending the data.
 * @param buffer A pointer to the memory location with outgoing data.
 * @param len The length of the buffered data to send.
 * @return Upon successful completion, the number of bytes which were sent is
 *     returned. Otherwise, -1 is returned and the global variable errno is set
 *     to indicate the error.
 */

size_t SEND(int socket, void *buffer, size_t len) {
    struct sockaddr_in local;
    tcpd_container packet;
    local.sin_family = AF_INET;
    local.sin_port = TCPD_LOCAL;
    local.sin_addr.s_addr = INADDR_ANY;
    
    memset(&packet, 0, sizeof packet);
    packet.dest = name;
    assert(len <= MAX_FILE_DATA);
    memcpy(&packet.data, buffer, len);
    usleep(500 * 1000);
    return sendto(socket, &packet, NET_HEADER + len, 0, (struct sockaddr *)&local, sizeof(local)) - NET_HEADER;
}

/**
 * Receives a message from a socket.
 * 
 * @param socket The socket receiving the data.
 * @param buffer A pointer to a suitable storage location for incoming data.
 * @param len The length of the data expected.
 * @return Returns the number of bytes received, or -1 if an error occurred.
 */

size_t RECV(int socket, void *buffer, size_t len) {
    static socklen_t namelen = sizeof(struct sockaddr_in);
    tcpd_container packet;
    ssize_t amt = recvfrom(socket, &packet, NET_HEADER + len, 0, NULL, &namelen);
    memcpy(buffer, &packet.data, amt - NET_HEADER);
    return amt - NET_HEADER;
}

/**
 * Deletes a descriptor.
 * 
 * @param socket The socket to close.
 * @return Upon successful completion, a value of 0 is returned. Otherwise, a
 *     value of -1 is returned and the global integer variable errno is set to
 *     indicate the error.
 */

int CLOSE(int socket) {
    /* This connection teardown code still needs support in tcpd.
     struct sockaddr_in local;
     tcpd_container packet;
     local.sin_family = AF_INET;
     local.sin_port = TCPD_LOCAL;
     local.sin_addr.s_addr = INADDR_ANY;
     
     memset(&packet, 0, sizeof packet);
     packet.dest = name;
     packet.flags = FIN;
     sendto(socket, &packet, NET_HEADER, 0, (struct sockaddr *)&local, sizeof(struct sockaddr_in));
     */
    return close(socket);
}

