/**
* Aaron D'Amico
* April 27, 2012
* 678 TCP over UDP project 
*/

/* import headers for semaphores, shared memory, printing output, file io */
#include "protocol.h"

void free_data()
{

}


int main (int argc, char *argv[])
{

	/* Set up ints for return values of semaphores, shared memory, and files */
	unsigned int fileNameLength = 0;
	unsigned int fileSize;
	int inputFileHandler;	

	/* hold various return values for error checks */
	int result;
	
	/* validate that the appropriate arguments have been passed in */
	if(argc < 4)
	{
		printf("usage: ftpClient <remote_ip_address> <remote_port> <file_to_transfer>\n");
		return(1);
	}
	
	/* if the file name passed in is greater than 20 characters, die */
	fileNameLength = strlen(argv[3]);
	if(fileNameLength > 20)
	{
		printf("input filename is longer than the 20 characters allotted.");
		return(1);
	}
	
	/* open file */
	inputFileHandler = open (argv[3], O_RDONLY);
	if ( inputFileHandler < 0)
	{
	    perror("error: ");
		return(1);
	}
	
	/* get file size */ 
	struct stat fileStat;
	fstat (inputFileHandler, &fileStat);
	fileSize = fileStat.st_size;
	printf("file size is %i", fileSize);
	printf("\n");

	/* set up shared memory */

	/* loop till end of file*/
		/* initialized values of semaphores arememlock = 1 and sync = 0 */
		/* read file into buffer */
		/* semaphore memlock wait */
		/* copy buffer to sharedmemory */
		/* semaphore memlock signal */
		/* semaphore sync signal */
		
	/* close up sharedmemory file and  */
	result = close(inputFileHandler);
	if (result  < 0)
	{
	    perror("error: ");
		return(1);
	}
	
	exit(0);
}
