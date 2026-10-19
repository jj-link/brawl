#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8007E99C(void*);

struct SoraMenuTitleObj {
    char pad0[0x2c];
    unsigned char flags;
    char pad1[0x54 - 0x2d];
    void* ptr54;
    int field58;
    int field5c;
};

extern "C" void fn_24_2B10(SoraMenuTitleObj* self) {
    self->flags &= ~0x02;
    void* p = __nw__FUlQ25Heaps8HeapType(1, 0x2a);
    if (p != 0) {
        p = fn_8007E99C(p);
    }
    self->ptr54 = p;
    self->field58 = 0;
    self->field5c = 0;
}
