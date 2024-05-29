#include <syscall_lib.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <lib.h>

extern void _updateRegisters();
extern uint64_t * _getRegisters();

#define ZERO_EXCEPTION_ID 0
#define OPCODE_EXCEPTION_ID 6 

#define RED 0x00FF0000
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF

#define EXCEPTION_ZERO  "ERROR ! (0) Division by zero\n"
#define EXCEPTION_OPCODE "ERROR ! (6) Opcode exception\n"


static void launchException(char * message); 
static void blueScreen();
static void dumpRegisters();

static char * regNames[] = {
    "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15", "RIP", "RSP"
};




void exceptionDispatcher(int exception) {
    _updateRegisters();    
    char * message; 
    if (exception == ZERO_EXCEPTION_ID)
        message = EXCEPTION_ZERO;
    else if (exception == OPCODE_EXCEPTION_ID){
        message = EXCEPTION_OPCODE;
    }
    launchException(message);

}

static void launchException(char * message) {
	sys_write(1, message, strlen(message), RED);
    dumpRegisters();
}

static void blueScreen() {
    sys_drawRectangle(BLUE, 0, 0, getScreenWidth(), getScreenHeight());
}

static void dumpRegisters(){
    uint64_t * registers = _getRegisters();
    char buffer[17];

    for(int i = 0; i < REGS_AMOUNT; i++){
        sys_write(1, regNames[i], strlen(regNames[i]), WHITE);
        sys_write(1, ": 0x", 4, WHITE);
        sys_write(1, itoaHex(registers[i], buffer), strlen(buffer), WHITE);
        sys_write(1, "\n", 1, WHITE);
    }
    
}