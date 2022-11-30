#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value[] = {0x04, 0x03, 0x00, 0x00, 0x00, 0x08};
    int len = sizeof(value)/sizeof(int);
    int copyValue[len];
    for(int i=0;i<len;i++)
    {
        copyValue[i] = value[i];
    }

    int receivedCRC = CRC(len,value);
    printf("CRC: 0x%X\n\n",receivedCRC);

    printf("Final packet is\n\n");
    for(int i=0;i<len;i++)
    {
        printf("0x%02X ",copyValue[i]);
    }
    printf("0x%02X ",((receivedCRC & (0xFF00))>>8));
    printf("0x%02X ",(receivedCRC & (0x00FF)));
    printf("\n\n\n");

    return 0;
}
