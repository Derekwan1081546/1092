#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	pid=fork();
	switch(pid)
	{
	   case -1:
	      printf("fail\n");
	      exit(-1);
	   case 0://child
	      printf("child ");
	      printf("(#pid = %d)\n",pid);

	      if(argc==3)
	      {
	        char *arg[]={"blake.txt","happy2.tmp",NULL};
	      	execvp("./mmv.out",arg);
	      }
	      else
	      {
	      	char *args[]={" ",NULL};
	      	execvp("./mmv.out",args);
	      }
	   default:
	      //wait(NULL);
	      printf("Successful! ");
	      printf("(#pid = %d)\n",pid);
	      exit(0);
	   
	}
	
	return 0;
}

