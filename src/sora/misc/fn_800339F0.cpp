#pragma force_active on
extern "C" void* fn_80023AC8(void);
extern "C" int fn_803CCAA4(int arg0);
extern "C" int fn_803D5870(int arg0);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void* heap, int type, unsigned long align);

struct Src {
    unsigned char pad[0x34];
    unsigned short m34;
    unsigned short m36;
};

struct Obj {
    unsigned char pad0[0x40];
    void* m40;
    unsigned short m44;
    unsigned short m46;
    unsigned char pad1[4];
    void* m4C;
    void* m50;
    unsigned char pad2[0xB4 - 0x54];
    int mB4;
};

extern "C" void fn_800339F0(Obj* self) {
    if (self->mB4 == 0) {
        Src* src = (Src*)fn_80023AC8();
        unsigned short t = src->m36;
        self->m44 = src->m34;
        self->m46 = t;
        self->m4C = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(self->m40, fn_803CCAA4(0), 0x20);
        self->m50 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(self->m40, fn_803D5870(0x40), 0x20);
        self->mB4 = 1;
    }
}
