#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
int isSocket(int fd)
{
	struct stat st;
	int err =  fstat(fd,&st);
	if(err < 0)
	{
		return -1;
	}
	if((st.st_mode & S_IFMT) == S_IFSOCK)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int  main()
{

	int ret = isSocket(0);
	printf("value 0 == [ %d ]\n",ret);

	int s = socket(AF_INET,SOCK_STREAM,0);
	ret = isSocket(s);
	printf("value s == [ %d ]\n",ret);
	return 0;
}
