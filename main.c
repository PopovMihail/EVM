#include "mySimpleComputer.h"


int main(){
	sc_memoryInit();
	
	sc_memorySet(9,7);
	sc_memorySet(5,7);
	sc_memorySet(60,7);
	sc_memorySet(95,7);
	
	sc_memorySave("my_memory.bin");
	my_print();
	
	sc_memoryLoad ("my_memory.bin");
	my_print();
	
	return 0;	
}
