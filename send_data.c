#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FIFO_SERVER "/home/drinksober/Desktop/weatherinfo/my_data"

send_data(char* argv)
{
	int fd;
	char w_buf[100];
	int nwrite;
	if(fd==-1)
	if(errno==ENXIO)
		printf("open error;no reading process\n");
	
	fd=open(FIFO_SERVER,O_WRONLY|O_NONBLOCK,0);
	if(argv==NULL)
		printf("Please send something\n");
	
	strcpy(w_buf,argv);
	if((nwrite=write(fd,w_buf,100))==-1)
	{
		if(errno==EAGAIN)
		printf("The FIFO has not been read yet. Please try later\n");
	}
	else 
	printf("write %s to the FIFO\n",w_buf);
}