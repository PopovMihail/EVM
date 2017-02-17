#include "mySimpleComputer.h"


///////
void my_print(){
	int i;
	for(i = 0; i < MEMSIZE; i++){
		if (i != 0 && i % 10 == 0)
			printf("\n");
		printf("%d", my_memory[i]);
	}
	printf("\n\n\n");
}
/////////
int sc_memoryInit (){
	int i;
	for(i = 0; i < MEMSIZE; i++)
		my_memory[i] = 0;
return 0;
}

int sc_memorySet (int address, int value){
	if(address < 0 || address >= MEMSIZE)
		return -1;
	else 
	my_memory[address] = value;
	return 0;		
}

int sc_memoryGet (int address, int *value){
	if(address < 0 || address >= MEMSIZE){
		return -1;
	}
	else  *value = my_memory[address];	
	return 0;
}

int sc_memorySave (char *filename){
	FILE *f ;
	f = fopen(filename, "w+b");
	if(f == NULL)
		return -1;
	int i;
	for(i = 0; i < MEMSIZE; i++)
		fwrite(&my_memory[i], sizeof(int), 1, f);
	fclose(f); 
	return 0;
}

int sc_memoryLoad (char * filename){
	FILE *f ;
	f = fopen(filename,"rb");
	if(f == NULL)
		return -1;
	int i;
	for(i = 0; i < MEMSIZE; i++)
		fread(my_memory, sizeof(my_memory), 1, f);
	fclose(f); 
	return 0;
}

/*************/
int sc_regInit (){
	reg = 0;
	return 0;
}

int sc_regSet (int my_reg, int value){
//	if (my_reg != FLAG_P || my_reg != FLAG_M || my_reg != FLAG_O || my_reg != FLAG_T || my_reg != FLAG_E) //проверка на некорректный флаг
//		return -1;
	if (value != 0 || value != 1) //некорректное значение
		return -1;
	
	if (value = 1)
		reg = reg | (1 << (my_reg - 1)); //установить значение флага в единицу
	else reg = reg & (~(1 << (my_reg - 1))); //установить значение флага в ноль
	//reg - переменная хранящая флаги; my_reg - номер разряда(по порядку)
	return 0;
}

int sc_regGet (int my_reg, int * value){
	//	if (my_reg != FLAG_P || my_reg != FLAG_M || my_reg != FLAG_O || my_reg != FLAG_T || my_reg != FLAG_E) //проверка на некорректный флаг
	//		return -1;
	//else  *value = (reg >> (my_reg - 1)) & 0x1;	//получаем значение определенного флага
	//reg - переменная хранящая флаги; my_reg - номер разряда(по порядку)
	return 0;
}

int sc_commandEncode (int command, int operand, int * value){
	/////
}

int sc_commandDecode (int value, int * command, int * operand){
	/////
}

