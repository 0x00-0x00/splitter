#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 4096

void *checkfd(FILE *fp)
{
    /*
        Function to check if file handle can be opened.
    */
    if (!fp) {
        fprintf(stderr, "Could not open file.\n");
        exit(1);
    }

}

int split_file(FILE *fp, int cut_value, char* out)
{

    /*
        Given a file handle, cut value and out file name, this function
        can split files.
    */
    checkfd(fp);
    int bytes_read, bytes_written, parts, count;
    char *buffer = malloc(sizeof(unsigned char) * BUFFSIZE);
    char *filename = malloc(sizeof(char) * 256);
    FILE *outfp;

    bytes_read = 0;
    bytes_written = 0;
    parts = 0;

    sprintf(filename, "%s.%d", out, parts);
    outfp = fopen(filename, "wb");
    checkfd(outfp);

    memset(buffer, '\0', BUFFSIZE);
    while ( (count = fread(buffer, sizeof(unsigned char), BUFFSIZE, fp)) != 0 ) {
        bytes_read += count;
        bytes_written += fwrite(buffer, sizeof(unsigned char), count, outfp);
        if (bytes_read > cut_value ) {
            bytes_read = 0;
            parts++;
            fclose(outfp);
            sprintf(filename, "%s.%d", out, parts);
            outfp = fopen(filename, "wb");
            checkfd(outfp);
        }
        memset(buffer, '\0', BUFFSIZE); // clear the buffer
    }

    free(buffer);
    free(filename);
    return 0;
}
