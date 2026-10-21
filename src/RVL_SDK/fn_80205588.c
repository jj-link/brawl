#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef unsigned long u32;

void CXInitUncompContextHuffman(void* arg0, u32 arg1) {
    u8* p = (u8*)arg0;
    *(u32*)(p + 0x00) = arg1;
    *(u32*)(p + 0x04) = 0;
    *(u8*)(p + 0x1C) = 0;
    *(s16*)(p + 0x18) = -1;
    *(u32*)(p + 0x0C) = (u32)(p + 0x20);
    *(u32*)(p + 0x14) = 0;
    *(u8*)(p + 0x1B) = 0;
    *(u32*)(p + 0x10) = 0;
    *(u8*)(p + 0x1A) = 0;
    *(u8*)(p + 0x1D) = 8;
    *(u32*)(p + 0x08) = 0;
}
