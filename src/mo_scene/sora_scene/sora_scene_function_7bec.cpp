#pragma force_active on
extern "C" void fn_1_13BEC(void);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
extern "C" void* fn_800B08A8(int);
extern "C" void* fn_2_30568(void*, int);
extern "C" unsigned long requestFill__8efScreenFfiiP8_GXColor(void* self, float, int, int, void*);
extern "C" void* g_efScreen;
extern "C" const float lbl_1_rodata_20;

struct Fn1_7BEC_Inner {
    int unk0;
    int unk4;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
    int unkC;
};

struct Fn1_7BEC_Self {
    char pad[0x104];
    Fn1_7BEC_Inner* unk104;
};

extern "C" void fn_1_7BEC(Fn1_7BEC_Self* self) {
    unsigned char c[4];
    int sp8;
    fn_1_13BEC();
    self->unk104 = (Fn1_7BEC_Inner*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2A, 0x10);
    self->unk104->unk0 = (int)fn_800B08A8(0x2A);
    self->unk104->unk4 = (int)fn_2_30568(self, 0x2A);
    c[2] = 0;
    self->unk104->unk8 = 0;
    c[1] = 0;
    self->unk104->unk9 = 1;
    c[0] = 0;
    c[3] = 0xFF;
    self->unk104->unkC = 0;
    sp8 = *(int*)c;
    self->unk104->unkA = (unsigned char)(requestFill__8efScreenFfiiP8_GXColor(g_efScreen, lbl_1_rodata_20, 7, 0x80, &sp8) >> 24);
}
