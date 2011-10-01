#include "jsint.h"

int main(){
	JSVirtualMachine *vm;
	JSByteCode *bc = NULL;

	beginSerial(9600);
	
	vm = js_vm_create(128, 0, 0);

	//bc = read_eeprom_bytecode(0x00);
	//bc = js_bc_read_data(_bytecode, _bytecode_size);

	//init_builtin_digitalio(vm);

	//int s = js_vm_execute(vm, bc);

	//js_bc_free(bc);
	js_vm_destroy(vm);
}
