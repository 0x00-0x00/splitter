#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "split.h"

#define BUFFSIZE 256

int main(int argc, char *argv[])
{
    FILE *fp;
    char c;
    char filename[BUFFSIZE];
    int bytes_read, bytes_cycle;

    if ( argc < 2 ) {
        fprintf(stderr, "Uso: %s -f ARQUIVO -s BYTES\n", argv[0]);
        exit(1);
    }

    while ( (c = getopt (argc, argv, "f:s:")) != -1 )
    {
        switch(c) {
            case 'f':
                memset(filename, '\0', BUFFSIZE);
                strncpy(filename, optarg, strlen(optarg));
                printf("File set to: %s\n", filename);
                break;

            case 's':
                bytes_cycle = atoi(optarg);
                printf("Maximum bytes set to: %d\n", bytes_cycle);
                break;
        }
    }

    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }
    split_file(fp, bytes_cycle, filename);
    printf("[+] Splitting procedure complete.\n");
    fclose(fp);
    return 0;
}
