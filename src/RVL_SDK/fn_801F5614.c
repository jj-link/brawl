#include <revolution/GX/GXInit.h>
#pragma force_active on
#pragma peephole off

void fn_801F5614(int arg0) {
    unsigned char *fifo = (unsigned char *)0xCC008000;
    unsigned char *gx;
    if (arg0 < 5) {
        *fifo = 8;
        gx = (unsigned char *)__GXData;
        *fifo = 0x30;
        *(unsigned int *)fifo = *(unsigned int *)(gx + 0x80);
        *fifo = 0x10;
        *(unsigned int *)fifo = 0x1018;
        *(unsigned int *)fifo = *(unsigned int *)(gx + 0x80);
    } else {
        *fifo = 8;
        gx = (unsigned char *)__GXData;
        *fifo = 0x40;
        *(unsigned int *)fifo = *(unsigned int *)(gx + 0x84);
        *fifo = 0x10;
        *(unsigned int *)fifo = 0x1019;
        *(unsigned int *)fifo = *(unsigned int *)(gx + 0x84);
    }
    *(unsigned short *)(gx + 2) = 1;
}