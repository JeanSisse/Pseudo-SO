#include <stdio.h>


#ifndef PROCESSOS
	#define PROCESSOS

	#ifdef PROCESSOS_SERVER
		#define EXT_PROCESSOS
	#else
		#define EXT_PROCESSOS extern
	#endif

	#define PROC_TEMPO_REAL	 0
	#define PROC_USUARIO_1	 1
	#define PROC_USUARIO_2	 2
	#define PROC_USUARIO_3	 3
	

	/*EXT_PROCESSOS void init_semaphoro();*/
	/*EXT_ESCALONADOR */
#endif