#include <stdio.h>
#include "../headers/memoria.h"


unsigned int aloca_mem(unsigned int qtd, int tipo_p){
	unsigned int offset = MAX_MEM;

	switch(tipo_p){
		case PROC_TEMPO_REAL:
			if(qtd > MEM_REAL){
				offset = 1026;
				return offset;
			}
			offset = verificacao(qtd, START, MEM_REAL);
			break;
		default:
			if(qtd > MEM_USER){
				offset = 1026;
				return offset;
			}
			offset = verificacao(qtd, MEM_REAL, MAX_MEM);
			break;
	}
	if(offset != MAX_MEM){
		for (int i = offset; i < qtd; i++){
			mem[i] = 1;
		}
	}
	return offset;
}

/*LEBERA A MEMORA QUE N ESTA EM USO*/
void desaloca(unsigned int offset,unsigned int qtd){

	for(int i = offset; i < qtd+offset; i++)
		mem[i] = 0;	
}

unsigned int verificacao(unsigned int qtd, unsigned int inic, unsigned int fim){
	unsigned int offset = MAX_MEM;
	int y;

	for(int i = inic; i < fim; i++){
		y = i;
		while(mem[y] == 0 && y < qtd+i)
			y++;
		if(y == qtd+i){
			offset = i;
			break;
		}else
			i = y;
	}

	return offset;
}