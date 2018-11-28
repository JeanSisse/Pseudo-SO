#include <stdio.h>
#include "../headers/escalonador.h"

/*------- funções básicas para uso de filas---*/
/*--------------------------------------------*/
void InicializaFila (fila **eFila) {
  *eFila = NULL;
}

/*--------------------------------------------*/
int FilaVazia (fila *pFila) {
  return (pFila == NULL);
}

/*--------------------------------------------*/
processo *FrenteFila(fila *pFila) {
  return pFila->p;
}

/*--------------------------------------------*/
void InsereFila(fila **eFila, processo *procs_atual) {
  fila *f1, *f2;
  f1 = malloc (sizeof (eFila));
  f1->p = procs_atual;
  f1->next = NULL;
  if (*eFila == NULL)
    *eFila = f1;
  else {
    f2 = *eFila;
    while (f2->next != NULL)
      f2 = f2->next;
    f2->next = f1;
  }
}

/*--------------------------------------------*/
processo *RetiraFila(fila **eFila) {
  fila *f1;
  processo *procs_atual;
  f1 = *eFila;
  *eFila = f1->next;
  procs_atual = f1->p;
  free (f1);
  return procs_atual;
}

void init_time(){
	segundos_executado = 0;
	/*n_processos = 0;*/
}
/*
void perror(){
	printf("ERROR: MEMORIA NAO ALOCADA PROCESSO %d\n", );
}*/

/*verifica se ainda existe processo na fila que ja pode ser executado*/
bool if_prox_processo(processo **p){

	if(!FilaVazia(fila_tempo_real)){
		*p = FrenteFila(fila_tempo_real);
		if((*p)->time_init <= segundos_executado){
			*p = RetiraFila(&fila_tempo_real);
			return true;
		}
	}

	if(!FilaVazia(fila_p1_usuario)){
		*p = FrenteFila(fila_p1_usuario);
		if((*p)->time_init <= segundos_executado){
			*p = RetiraFila(&fila_p1_usuario);
			return true;
		}
	}

	if(!FilaVazia(fila_p2_usuario)){
		*p = FrenteFila(fila_p2_usuario);
		if((*p)->time_init <= segundos_executado){
			*p = RetiraFila(&fila_p2_usuario);
			return true;
		}
	}

	if(!FilaVazia(fila_p3_usuario)){
		*p = FrenteFila(fila_p3_usuario);
		if((*p)->time_init <= segundos_executado){
			*p = RetiraFila(&fila_p3_usuario);
			return true;
		}
	}
	return false;
}

void preenche_fila(){

	int i = 0;
	processo *test, *p;

	if(!FilaVazia(fila_processos))
		p = FrenteFila(fila_processos);

	/*test = p;
	if(test != NULL){
		printf("test->pid: %d\n", test->pid);
		printf("test->mem_offset: %d\n", test->mem_offset);
		printf("test->time_init: %d\n", test->time_init);
		printf("test->prioridade: %d\n", test->prioridade);
		printf("test->time_exec: %d\n", test->time_exec);
		printf("test->qtd_blocos: %d\n", test->qtd_blocos);
		printf("test->impressora: %d\n", test->impressora);
		printf("test->scaner: %d\n", test->scaner);
		printf("test->modem: %d\n", test->modem);
		printf("test->disco: %d\n", test->disco);
	}*/


	/*printf("i = %d; n_processos = %d, p->time_init: %d\n", i, n_processos, p->time_init);*/
	while(i < n_processos && p->time_init < segundos_executado + 1){
		printf("CHEGUEI NA EXECUÇÃO\n");
		switch(p->prioridade){
			case PROC_TEMPO_REAL:
				InsereFila(&fila_tempo_real, p);
				printf("PROC_TEMPO_REAL\n");
				/*while(!FilaVazia(fila_tempo_real)){
					test = RetiraFila(&fila_tempo_real);
					if(test != NULL){
						printf("test->pid: %d\n", test->pid);
						printf("test->mem_offset: %d\n", test->mem_offset);
						printf("test->time_init: %d\n", test->time_init);
						printf("test->prioridade: %d\n", test->prioridade);
						printf("test->time_exec: %d\n", test->time_exec);
						printf("test->qtd_blocos: %d\n", test->qtd_blocos);
						printf("test->impressora: %d\n", test->impressora);
						printf("test->scaner: %d\n", test->scaner);
						printf("test->modem: %d\n", test->modem);
						printf("test->disco: %d\n", test->disco);
					}
				}*/
				break;
			case PROC_USUARIO_1:
				InsereFila(&fila_p1_usuario, p);
				printf("PROC_USUARIO_1\n");
				break;
			case PROC_USUARIO_2:
				InsereFila(&fila_p2_usuario, p);
				printf("PROC_USUARIO_2\n");
				break;
			case PROC_USUARIO_3:
				InsereFila(&fila_p3_usuario, p);
				printf("PROC_USUARIO_3\n");
				break;

			default:
				break;
		}
		if(!FilaVazia(fila_processos))
			p = RetiraFila(&fila_processos);

		if(!FilaVazia(fila_processos))
			p = FrenteFila(fila_processos);
		i++;
	}
}


void insere_final_fila(processo *p){
	switch(p->prioridade){
		
	}
}

bool tem_processo(){
	return ( !FilaVazia(fila_processos));
}

/***************ORDENA LISTA DE PROCESSOS PELO TEMPO DE EXECUÇÃO*******************/
void OrdenaAlteraPonteiros(processo **lProcessos) {
	processo *p1, *p2, *p3, *paux;
  
	if (*lProcessos != NULL)  {
		p1 = *lProcessos;
		while (p1->next != NULL) {
      		p2 = p1->next;
      		while (p2 != NULL) {
      			/*printf("p1->time_init = %d\n", p1->time_init);
      			printf("p2->time_init = %d\n", p2->time_init);*/
        		/*printf("AQUI ENTRA ALGUMA VEZ?\n");*/
        		if (p1->time_init > p2->time_init){

        			p3 = *lProcessos;
        			
        			if(p3 != p1)
	        			while(p3->next != p1)
	        				p3 = p3->next;

	          		if (p1->next == p2) {
	            		p1->next = p2->next;
	            		p2->next = p1;
	            		p3->next = p2;

	            		if (*lProcessos == p1)
	              			*lProcessos = p2;

	            		paux = p1;
	            		p1 = p2;
	            		p2 = paux;
	          		}else{

			            paux = p1;
			            while(paux->next != p2)
			            	paux = paux->next;
			            paux->next = p1;
			            p3->next = p2;
			            p3 = p1->next;

			            p1->next = p2->next;
			            p2->next = p3;

			            if (*lProcessos == p1)
			              *lProcessos = p2;

			            paux = p1;
			            p1 = p2;
			            p2 = paux;        
	          		}
        		}  
        		p2 = p2->next;  
      		}
      		p1 = p1->next;  
   		}
  	}
}

/**********************************************************************/
void read_input_file(char *input_file){

	FILE *read_input;

	int timInit, prioridade, timeExec, bm;
	int print, scan, modem, disco;
	int id = 0;
	
	processo *process;

	process = NULL;
	processo *p1, *p2;

	read_input = fopen(input_file, "r");

	if(read_input == NULL){
		printf("Não foi possivel abrir o arquivo de processos.\n");
	}else{
		while((fscanf (read_input, "%d, %d, %d, %d, %d, %d, %d, %d",\
		 &timInit, &prioridade, &timeExec, &bm, &print, &scan, &modem, &disco)) != EOF){
			/*((fscanf (read_input, "%[^\n]", str)) != EOF)*/
			n_processos+=1;
			p1 = malloc(sizeof(processo));
			p1->next = NULL;
			if(p1 != NULL){
				p1->pid = id;
				p1->mem_offset = -1;
				p1->time_init = timInit;
				p1->prioridade = prioridade;
				p1->time_exec = timeExec;
				p1->qtd_blocos = bm;
				p1->impressora = print;
				p1->scaner = scan;
				p1->modem = modem;
				p1->disco = disco;
				id++;
				if(process == NULL)
					process = p1;
				else
					p2->next = p1;
				p2 = p1;
			}else{
				printf("Não foi possivel alocar a memória para criar lista de processos.\n");
				exit(1);
			}
			/*printf("N_PROCESSOS %d\n", n_processos);*/
		}
		fclose(read_input);
	}
	OrdenaAlteraPonteiros(&process);


	p2 = process;
	InicializaFila(&fila_processos);

	while(p2 != NULL){
		InsereFila(&fila_processos, p2);
		p2 = p2->next;
	}

	/*while(!FilaVazia(fila_processos)){
		p2 = RetiraFila(&fila_processos);

			printf("p2->pid: %d\n", p2->pid);
			printf("p2->mem_offset: %d\n", p2->mem_offset);
			printf("p2->time_init: %d\n", p2->time_init);
			printf("p2->prioridade: %d\n", p2->prioridade);
			printf("p2->time_exec: %d\n", p2->time_exec);
			printf("p2->qtd_blocos: %d\n", p2->qtd_blocos);
			printf("p2->impressora: %d\n", p2->impressora);
			printf("p2->scaner: %d\n", p2->scaner);
			printf("p2->modem: %d\n", p2->modem);
			printf("p2->disco: %d\n", p2->disco);

			printf("\n");
	}
*/
	init_execution(process);
}



void init_execution(processo *procs){
	unsigned int offset;

	processo *p;

	InicializaFila(&fila_tempo_real);
	InicializaFila(&fila_p1_usuario);
	InicializaFila(&fila_p2_usuario);
	InicializaFila(&fila_p3_usuario);

	init_time();

	while(tem_processo()){
		/*printf("CHEGUEI NA EXECUÇÃO\n");*/
		preenche_fila();
		if(if_prox_processo(&p)){
			if(p->mem_offset == -1){
				offset = aloca_mem(p->qtd_blocos, p->prioridade);
				if(offset == MAX_MEM){
					printf("ERROR: MEMORIA NAO ALOCADA PROCESSO %d\n", p->pid);
					p->prioridade = p->prioridade + 1;
					if(p->prioridade > 3)
						p->prioridade = 3;
					insere_final_fila(p);
				}
			}
			printf("EXITSTE PROCESSO %d\n", offset);
		}
	}
}