#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/processos.h"
#include "../headers/memoria.h"

#ifndef ESCALONADOR
#define ESCALONADOR

	#ifdef ESCALONADOR_SERVER
		#define EXT_ESCALONADOR
	#else
		#define EXT_ESCALONADOR extern
	#endif

	typedef struct processos{
		int pid;
		int mem_offset;
		int time_init;
		int prioridade;
		int time_exec;
		int qtd_blocos;
		int impressora;
		int scaner;
		int modem;
		int disco;

		struct processos *next;
	}processo;
	
	typedef struct structFila{
		processo *p;
		struct structFila *next;
	}fila;

	int segundos_executado;
	int n_processos;

	fila *fila_tempo_real;
	fila *fila_p1_usuario;
	fila *fila_p2_usuario;
	fila *fila_p3_usuario;
	fila *fila_processos;

	EXT_ESCALONADOR void InicializaFila (fila **eFila);
	EXT_ESCALONADOR int FilaVazia (fila *pFila);
	EXT_ESCALONADOR processo *FrenteFila(fila *pFila) ;
	EXT_ESCALONADOR void InsereFila(fila **eFila, processo *procs_atual);
	EXT_ESCALONADOR processo *RetiraFila(fila **eFila);

	EXT_ESCALONADOR void read_input_file(char *input_file);
	EXT_ESCALONADOR void init_execution(processo *procs);
	EXT_ESCALONADOR void OrdenaAlteraPonteiros(processo **lProcessos);
	EXT_ESCALONADOR bool tem_processo();
	EXT_ESCALONADOR void preenche_fila();
	EXT_ESCALONADOR bool if_prox_processo();
	EXT_ESCALONADOR void insere_final_fila(processo *p);

	/*EXT_ESCALONADOR */
#endif
