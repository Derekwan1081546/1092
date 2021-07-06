#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd1, fd2;
	mode_t mode = S_IRWXU;
	if (argc == 2)
	{
		fd1 = creat(argv[1], mode);
		fd2 = open(argv[0], O_RDONLY, 0);
	}
	else
	{
		fd1 = creat("happy.tmp", mode);
		fd2 = open("blake.txt", O_RDONLY, 0);
	}
	char line[40] = "\\\\----Say Hello to s1081546!----\\\\\n";
	write(fd1, line, strlen(line));
	char tmp[50];
	while (read(fd2, tmp, 50))
	{
		write(fd1, tmp, 50);
		for (int i = 0; i < 50; i++)
		{
			tmp[i] = 0;
		}
	}
	close(fd1);
	close(fd2);
	return 0;
}
