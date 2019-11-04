#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[], char *envp[]){
	printf ("Simple.c - sou %5d, filho de %5d\n", getpid(), getppid()) ;
	sleep(5);
	exit (0) ;
}
