#pragma force_active on
extern unsigned char* const __GXData;

void __GXFlushTextureState(void) {
    unsigned char* fifo = (unsigned char*)0xCC008000;
    *fifo++ = 0x61;
    *(unsigned int*)(fifo - 1) = *(unsigned int*)(__GXData + 0x174);
    *(unsigned short*)(__GXData + 2) = 0;
}
