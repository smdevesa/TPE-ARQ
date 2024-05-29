#include <syscall_lib.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <lib.h>

extern uint64_t * _getSnapshot();

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
    "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15", "RSP", "RIP", "RFLAGS", "CS", "SS"
};

static int regsAmount = (sizeof(regNames) / sizeof(regNames[0]));


void exceptionDispatcher(int exception) {
    char * message;
    if (exception == ZERO_EXCEPTION_ID)
        message = EXCEPTION_ZERO;
    else if (exception == OPCODE_EXCEPTION_ID){
        message = EXCEPTION_OPCODE;
    }
    launchException(message);
}

static void launchException(char * message) {
    sys_clearScreen();
    blueScreen();
    setScale(2);
	sys_write(1, message, strlen(message), RED);
    dumpRegisters();

    char * continueMessage = "\nPress any key to relaunch shell...";
    sys_write(1, continueMessage , strlen(continueMessage), WHITE);

    int readBytes = 0;
    char c;
    _sti();
    while(readBytes == 0){
        readBytes = sys_read(0, &c, 1);
    }
}

static void blueScreen() {
    sys_drawRectangle(BLUE, 0, 0, getScreenWidth(), getScreenHeight());
}

static void dumpRegisters(){
    uint64_t * registers = _getSnapshot();
    char buffer[17];

    for(int i = 0; i < regsAmount; i++){
        itoaHex(registers[i], buffer);
        int zeroDigits = 16 - strlen(buffer);

        sys_write(1, regNames[i], strlen(regNames[i]), WHITE);
        sys_write(1, ": 0x", 4, WHITE);
        for(int j = 0; j < zeroDigits; j++){
            sys_write(1, "0", 1, WHITE);
        }
        sys_write(1, itoaHex(registers[i], buffer), strlen(buffer), WHITE);
        sys_write(1, "\n", 1, WHITE);
    }
}