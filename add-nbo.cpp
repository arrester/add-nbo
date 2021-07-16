#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    uint32_t value1;
    uint32_t value2;
    uint32_t sum;
    FILE *fp1, *fp2;

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    fread(&value1, sizeof(value1), 1, fp1);
    fread(&value2, sizeof(value2), 1, fp2);

    value1 = ntohl(value1);
    value2 = ntohl(value2);
    sum = value1 + value2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", value1, value1, value2, value2, sum, sum);

    fclose(fp1);
    fclose(fp2);
}