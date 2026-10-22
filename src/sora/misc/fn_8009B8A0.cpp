#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad[0x58];
    void* unk58;
    u8 unk5C;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80082438(void*);

extern "C" void fn_8009B8A0(Obj* self) {
    if (self->unk5C) {
        if (!self->unk58) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x70, 0xD);
            if (p)
                p = fn_80082438(p);
            self->unk58 = p;
        }
    }
}
