#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    size_t mem_size = 256;
    char *memory = malloc(mem_size);
    int pid = getpid();
    size_t len = 0;

    memset(memory, 0, mem_size);

    printf("Input string: ");
    getline(&memory, &len, stdin);

    printf("Now execute\n");
    printf("sudo ./app2 %d %lx %lu\n", pid, (long unsigned int)memory, mem_size);

    printf("Press any key\n");
    getchar();

    printf("<memory> has changed to: %s\n", memory);

    free(memory);

    return 0;
}