# Makefile for client and server

#LIBS = -lxnet -lsocket -lpthread
CFLAGS = -Wall -g -o
CODELIB = api.c buffers.c checksum.c protocol.h
 
all: ftpClient ftpServer tcpd tcpdServer

ftpClient: ftpClient.c 
	gcc $(CFLAGS) ClientEXE/ftpClient ftpClient.c $(CODELIB) $(LIBS)
	
ftpServer: ftpServer.c
	gcc $(CFLAGS) ServerEXE/ftpServer ftpServer.c $(CODELIB) $(LIBS)	
	
tcpd: tcpd.c
	gcc $(CFLAGS) ClientEXE/tcpd tcpd.c $(CODELIB) $(LIBS)
	
tcpdServer: tcpd.c
	gcc $(CFLAGS) ServerEXE/tcpd tcpd.c $(CODELIB) $(LIBS)

clean:
	rm -f ClientEXE/*.* ClientEXE/*.*