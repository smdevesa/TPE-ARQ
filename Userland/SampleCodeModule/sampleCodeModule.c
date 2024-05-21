/* sampleCodeModule.c */

#include <syscalls.h>
#include <iolib.h>

int main() {
    // test for fgets
    printf("Enter a string: \n");
    char buffer[100];
    fgets(buffer, 100);
    printf("You entered: ");
    printf(buffer);
    return 0;
}