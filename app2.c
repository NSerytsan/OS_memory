#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("Usage: app2 <pid> <addr> <length>\n");
        exit(1);
    }

    int pid = strtol(argv[1], NULL, 10);
    unsigned long addr = strtoul(argv[2], NULL, 16);
    size_t len = strtol(argv[3], NULL, 10);

    char *proc_mem = malloc(256);
    sprintf(proc_mem, "/proc/%d/mem", pid);

    printf("Opening %s, address is %lx\n", proc_mem, addr);

    int fd_proc_mem = open(proc_mem, O_RDWR);
    if (fd_proc_mem == -1)
    {
        printf("Could not open %s\n", proc_mem);
        exit(1);
    }

    char *buf = malloc(len);

    lseek(fd_proc_mem, addr, SEEK_SET);
    read(fd_proc_mem, buf, len);

    printf("String at %lx in process %d is:\n", addr, pid);
    printf("%s\n", buf);

    printf("Input new string: ");
    getline(&buf, &len, stdin);

    lseek(fd_proc_mem, addr, SEEK_SET);

    if (write(fd_proc_mem, buf, len) == -1)
    {
        printf("Error while writing\n");
        exit(1);
    }

    printf("\nNow, this string is modified\n");

    free(buf);
    free(proc_mem);

    return 0;
}
