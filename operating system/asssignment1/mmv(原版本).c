#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	FILE *fp,*fblake;
	if(argc==2)
	{
	    fp = fopen(argv[1],"w+");
	    fblake = fopen(argv[0],"r+");
	}
	else
	{
	    fp = fopen("happy.tmp","w+");
	    fblake = fopen("blake.txt","r+");
	}
	char line[] = "\\----Say Hello to s1081546!----\\";
	char tmp[100];
	fprintf(fp,"%s\n",line);
	while(fgets(tmp,100,fblake)!=NULL)
	{
	     fprintf(fp,"%s",tmp);	
	}
	   
	fclose(fblake);
	fclose(fp);
	return 0;
}
