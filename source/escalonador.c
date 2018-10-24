#include <stdio.h>
#include "../headers/escalonador.h"

void read_input_file(char *input_file){

	FILE *read_input;
	char str[10];

	memset(str, '\0', 10);

	read_input = fopen(input_file, "r");

	if(read_input == NULL){
		printf("Não foi possivel abrir o arquivo de processos.\n");
	}else{
		while((fscanf (read_input, "%[^\n]", str)) != EOF){

		}
	}
}