#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8007E99C(void*);

void fn_24_15F4(unsigned char* self) {
    self[0x2c] &= ~2;
    void* p = __nw__FUlQ25Heaps8HeapType(1, 0x2a);
    if (p != 0) {
        p = fn_8007E99C(p);
    }
    *(void**)(self + 0x54) = p;
    *(unsigned int*)(self + 0x58) = 0;
    *(unsigned int*)(self + 0x5c) = 0;
}
}
