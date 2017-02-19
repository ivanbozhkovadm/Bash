#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
	
int main(int argc,char **argv)
{
	char *p1 = argv[1];
	char *p2 = argv[2];
	unsigned short int number= atoi(argv[3]);

	int fd1 = open(p1,O_RDONLY);
	int fd2 = open(p2,O_RDONLY);

	if( fd1 == -1 || fd2 == -1)
	{ 
		write(1,"ERROR! \n",9); 
		exit(8);
	}
	
	if (number < 5 || number> 50)
	{
		write(1,"ERROR! [5,50] \n",15);
		exit(9);
	}

	int  fdNewFile  = open("myNewFile", O_CREAT | O_WRONLY | O_TRUNC  ,"r+" );

	char c,b;
	int i=0;
	int j=0;


	int breaking=1;
	while(breaking){
	
		
		while(read(fd1,&c,1))
			{
				write(fdNewFile,&c,1);
				
				if(c=='\n')
				{
					i++;
				}
				
				if(i == number)
				{
					i=0;
					break;
				}
			}
		
		while(read(fd2,&b,1))
			{
				write(fdNewFile,&b,1);
				
				if(b == '\n')
				{
					j++;
				}
				
				if(j == number)
				{
					j=0;
					break;
				}
			}
		if( read(fd1,&c,1) ==0 && read(fd2,&b,1) == 0 )
		{
			breaking =0;
		}
	}


	close(fd1);
	close(fd2);
	close(fdNewFile);

return 0;
}







