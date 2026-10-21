#pragma force_active on
extern unsigned char* __GXData;

void fn_801F13C8(void) {
    unsigned char* fifo = (unsigned char*)0xCC008000;
    unsigned char* gx;

    *fifo++ = 0x61;
    gx = __GXData;
    *(unsigned int*)(fifo - 1) = *(unsigned int*)(gx + 0x254);
    *(unsigned short*)(gx + 2) = 0;
}
