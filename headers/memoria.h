#include <stdio.h>

#include "../headers/processos.h"

#ifndef MEMORIA
	#define MEMORIA

	#ifdef MEMORIA_SERVER
		#define EXT_MEMORIA
	#else
		#define EXT_MEMORIA extern
	#endif
	
	#define MAX_MEM		1024
	#define MEM_REAL	64
	#define MEM_USER	MAX_MEM - MEM_REAL

	#define	START		0

	int mem[MAX_MEM];


	EXT_MEMORIA unsigned int aloca_mem(unsigned int qtd, int tipo_p);
	EXT_MEMORIA unsigned int verificacao(unsigned int qtd, unsigned int inic, unsigned int fim);
	EXT_MEMORIA void desaloca(unsigned int offset,unsigned int qtd);
#endif