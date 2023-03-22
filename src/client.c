#include <stdio.h>
#include <signal.h>
#include <unistd.h> //getpid, sleep
#include <stdlib.h>
#include "../includes/libft.h"

static void handle_string(int pid, char *msg)
{
	int bin_rep;
	int i;

	bin_rep = 0b10000000; 
			//	01000001
	i = 0;
	
	while (*msg != '\0')
	{
		while (i != 8)
		{
			if ((*msg & bin_rep >> i) == 0)
			{
				kill(pid, SIGUSR1);
				usleep(500);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(500);
			}
			i++;
		}
		i = 0;
		msg++;
	}
}

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s\n", "dude no");
		return (0);
	}
	handle_string(atoi(argv[1]), argv[2]);
	
	return 0;
}