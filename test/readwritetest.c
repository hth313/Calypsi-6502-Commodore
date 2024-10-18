#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <calypsi/stubs.h>
#include <calypsi/intrinsics6502.h>
#include <mega65.h>
#include "lib.h"

#define ASCIIKEY (*(volatile uint8_t *)0xd610)

uint8_t pcxheader[128];

int main()
{
    printf("LIBC FILE ACCESS TEST 0.1\r\n");
    printf("OPENING EXISTING FILE!\r");
    FILE *pcxfile = fopen("COUGAR2.PCX,P,R", "rb");
    if (pcxfile == NULL)
    {
        printf("FAILED OPENING FILE!\r\n");
    }

    fread(pcxheader, 1, 128, pcxfile);

    for (uint8_t i = 0; i < 8; i++)
    {
        printf("%01x0:", i);
        for (uint8_t j = 0; j < 16; j++)
        {
            printf(" %02x", pcxheader[(i << 4) | j]);
        }
        printf("\r");
    }

    if (pcxheader[0] != 0x0a)
    {
        printf("NOT A PCX FILE!\r\n");
    }
    fclose(pcxfile);

    FILE *datafile = fopen("TESTDATA,S,W", "wb");
    if (datafile == NULL)
    {
        printf("FAILED TO WRITE DATAFILE!");
    }
    fprintf(datafile, "THIS IS SOME TEST DATA!\r");
    fprintf(datafile, "01234567890123456789012\r");
    fprintf(datafile, "THIS IS MORE TEST DATA!\r");
    printf("THIS IS NOT IN THE DATA FILE!\r");
    fclose(datafile);

    datafile = fopen("TESTDATA,S,R", "rb");
    if (datafile == NULL)
    {
        printf("FAILED TO READ DATA FILE!\r");
    }
    size_t bytes_read;
    uint8_t counter;
    printf("REREADING FILE\r");
    bytes_read = fread(pcxheader, 1, 20, datafile);
    if (bytes_read != 20)
    {
        printf("FAILED TO READ 20 BYTES! GOT: %d\r", bytes_read);
    }
    printf("READ 1 COMPLETE!\r");
    bytes_read = fread(pcxheader, 1, 20, datafile);
    if (bytes_read != 20)
    {
        printf("FAILED TO READ 20 BYTES! GOT: %d\r", bytes_read);
    }
    printf("READ 2 COMPLETE!\r");
    bytes_read = fread(pcxheader, 1, 20, datafile);
    if (bytes_read != 20)
    {
        printf("FAILED TO READ 20 BYTES! GOT: %d\r", bytes_read);
    }
    printf("READ 3 COMPLETE!\r");
    bytes_read = fread(pcxheader, 1, 20, datafile);
    if (bytes_read != 12)
    {
        printf("FAILED TO READ 12 BYTES! GOT: %d\r", bytes_read);
    }
    printf("READ 4 COMPLETE!\r");
    bytes_read = fread(pcxheader, 1, 20, datafile);
    if (bytes_read != 0)
    {
        printf("EXPECTED EOF RESULT! GOT: %d\r", bytes_read);
    }
    printf("READ 5 COMPLETE!\r");
    printf("TEST COMPLETE.\r\n");
    return 0;
}
