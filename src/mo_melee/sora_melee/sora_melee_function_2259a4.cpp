#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_225A14(void*);

extern "C" {
void* fn_27_2259A4() {
    unsigned char* p = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x64, 0xf);
    if (p != 0) {
        *(unsigned int*)(p + 0x00) = 0;
        *(unsigned char*)(p + 0x04) = 0;
        *(unsigned int*)(p + 0x08) = 0;
        *(unsigned int*)(p + 0x50) = 0;
        *(unsigned char*)(p + 0x62) = 0;
        *(void**)(p + 0x00) = __nw__FUlQ25Heaps8HeapType(0xEC, 0xf);
        fn_27_225A14(p);
    }
    return p;
}
}
