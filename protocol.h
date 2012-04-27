#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


/* API ************************************************************************/

int SOCKET();
int BIND(int, char*, unsigned short);
int ACCEPT(int);
int CONNECT(int, char*, char*);
size_t SEND(int, void*, size_t);
size_t RECV(int, void*, size_t);
int CLOSE(int);

/* buffers ************************************************************************/


/* checksum ************************************************************************/


/* datagram packet ******************************************************************/
