/*Exibe e altera o 'stack size'.
Para simplificar o programa, o tratamento de erro foi omitido.
*/

#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>

void procedimento(){
	char vet[9*1024*1024];  
	printf("\nVetor de 9MB alocado dentro do procedimento\n");	
}

int main (int argc, char **argv)
{
	printf ("Ola, sou o processo %5d\n", getpid()) ;

	/***INÍCIO***/
	/***Exiba o tamanho atual da pilha ***/
	struct rlimit rl;    
	getrlimit(RLIMIT_STACK, &rl);
	printf("\nSoft limit: %lld \nHard limit: %lld\n", 
			(long long int)rl.rlim_cur, (long long int)rl.rlim_max);
	/*** FIM ***/

	/***INÍCIO***/
	/*** Altere o tamanho da pilha para 16MB ***/
	rl.rlim_cur = 16 * 1024 * 1024; //16MB
	setrlimit(RLIMIT_STACK, &rl);
	/*** FIM ***/

	/***INÍCIO***/
	/***Exiba o tamanho da pilha após a alteração***/


	/***FIM***/

	/***INÍCIO***/
	/*** Altere o tamanho da pilha para 10MB usando o comando: 
		$ ulimit -s 10240
		Execute este programa e verifique se o tamanho da pilha será alterado
		para 16MB. Explique.
	***/
	/*** FIM ***/


	/***INÍCIO***/
	/****É possível alocar um vetor de 9MB na pilha após alterar o tamanho 
	para 16MB ? Tente alocar um vetor de 9MB e execute o programa. Discuta. ****/	


	/*** FIM ***/

	/***INÍCIO***/
	/***Após alterar o tamanho da pilha para 16MB, é possível alocar um vetor
	 de 9MB dentro de um procedimento? Implemente o procedimento para testar.
	Discuta.***/
	//procedimento(); 
	/*** FIM ***/

	/***INÍCIO***/
	/*** É possível alocar um vetor de 20MB usando o comando malloc? 
		Implemente o código para testar e explique.	***/

	/*** FIM ***/

	/*** Enquanto o processo esta' em estado 'sleep', use o comando: 
	cat /proc/ID/limits para ver o 'stack size' ***/
	//sleep(60);
	return 0;
}
