
/*modulo responsável pela liberação ou não dos recursos*/

#define RECURSOS_SERVER
#include "../headers/recursos.h"


/*INICIALIZAÇÃO DOS SEMAFOROS*/
void init_semaphoro(){
	sem_init(&modem, 0, 1);			/*Inicia semaforo com uma permição*/
	sem_init(&driver, 0, 2);		/*Inicia semaforo com duas permição*/
	sem_init(&scanner, 0, 1);		/*Inicia semaforo com uma permição*/
	sem_init(&impressora, 0, 2);	/*Inicia semaforo com duas permições*/
}

int controle_recursos(int recurso){

	int try_recurso = 0;

	switch(recurso){
		case MODEM:
			if(!sem_trywait(&modem))
				try_recurso = 1;
			break;

		case DRIVER:
			if(!sem_trywait(&driver))
				try_recurso = 1;
			break;

		case SCANNER:
			if(!sem_trywait(&scanner))
				try_recurso = 1;
			break;

		case IMPRESSORA:
			if(!sem_trywait(&impressora))
				try_recurso = 1;
			break;

		default:
			printf("Recurso solicitado n encontrado.\n");
			break;

		return try_recurso;
	}
	return 0;
}