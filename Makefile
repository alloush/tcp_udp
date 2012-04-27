# Makefile for client and server

#LIBS = -lxnet -lsocket -lpthread
CFLAGS = -Wall -g -o
CODELIB = api.c buffers.c checksum.c checksum.h protocol.h
 
all: ftpClient ftpServer tcpd tcpdServer

ftpClient: ftpClient.c $(CODELIB)
	gcc $(CFLAGS) ClientEXE/ftpClient ftpClient.c $(LIBS)
	
ftpServer: ftpServer.c $(CODELIB)
	gcc $(CFLAGS) ServerEXE/ftpServer ftpServer.c $(LIBS)	
	
tcpd: tcpd.c $(CODELIB)
	gcc $(CFLAGS) ClientEXE/tcpd tcpd.c $(LIBS)
	
tcpdServer: tcpd.c $(CODELIB)
	gcc $(CFLAGS) ServerEXE/tcpd tcpd.c $(LIBS)			

clean:
	rm -f ClientEXE/*.o ClientEXE/*.o ServerEXE/ftpServer ClientEXE/ftpClient ServerEXE/tcpd ClientEXE/tcpd