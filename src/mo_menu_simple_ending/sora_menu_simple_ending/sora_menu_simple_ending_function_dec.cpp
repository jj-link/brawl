#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8007E99C(void*);
void fn_19_DEC(char* self);
}

void fn_19_DEC(char* self) {
    *(u8*)(self + 0x2c) &= ~0x02;
    void* p = __nw__FUlQ25Heaps8HeapType(1, 0x2a);
    if (p) {
        p = fn_8007E99C(p);
    }
    *(void**)(self + 0x9ac) = p;
    *(int*)(self + 0x9b0) = 0;
    *(int*)(self + 0x9b4) = 0;
}
