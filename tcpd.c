/*
* Aaron D'Amico
* April 27, 2012
* 678 TCP over UDP project 
*/

/* import headers for semaphores, shared memory, printing output, file io */
#include "protocol.h"

int main (int argc, char *argv[])
{
	
	/* set up ints for semaphore, sharedmemory, sockets and pipes  */
	/* pipes are used to communicate with timer process */
	
	/* set up sockets using api of tcp calls over udp */

	/* loop */		
		/**
		* semaphores initialized values are memlock = 1 and sync = 0
		* semaphore sync wait
		* semaphore memlock wait
		* critical section, read from buffer
		* semaphore memlock signal
		*/
		
		/**
		* do stuff to the just read buffer
		* send to timer process
		* add to rolling send buffer
		* send to timer via sockets
		*/
	
	/**
	* close sockets, sharedmemory and pipes
	*/

}


