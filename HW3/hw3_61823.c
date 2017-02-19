#include <fcntl.h>
#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	int fd = open(argv[1],O_RDONLY);
	char c;
	char arr[200];
	int i=0;

	while(read(fd,&c,1))
	{
		arr[i]=c;
		i++;
	}
	
	printf("\n ASCI - SYMBOL - FREQUENCY \n");

	int k;
	for(k=0; k<i;k++)
	{
		char letter = arr[k];

		if(letter != '\0')
		{
			int counter=0;
			int m;
			
			for(m=0;m<i;m++)
			{
				if(arr[m] == letter)
				{
					counter++;
					arr[m]='\0';
				}

			}
			
			if(letter == '\n')
			{
				printf("%d - new lines - %d \n",letter,counter);
			}
			else if( letter == ' ')
			{
				printf("%d - spaces - %d \n", letter,counter);
			}
			else
			{
				printf("%d - %c - %d \n", letter, letter, counter);
			}
		}

	}

close(fd);
return 0;
}









