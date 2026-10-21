#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80242908(void*);

void fn_802468B8(void* p) {
    *(u16*)((char*)p + 2) = 3;
    *(u16*)((char*)p + 4) = 0;
    *((char*)p + 8) = 5;
    *((char*)p + 9) = 0x10;
    *((char*)p + 10) = 0;
    fn_80242908(p);
}
