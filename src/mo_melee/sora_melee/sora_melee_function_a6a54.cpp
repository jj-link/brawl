#include <types.h>
#pragma force_active on

struct Vec2 {
    f32 x;
    f32 y;
};

struct Arg3 {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    s32 unk4;
    s32 unk8;
};

struct Heap {
    u8 pad0[0x8];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x8];
    s32 unk18;
    union {
        s32 unk1C;
        u8 unk1C_b[4];
        struct { u8 top : 1; u8 rest : 7; } flags;
        struct { unsigned int high : 24; unsigned int low : 8; } bits;
    };
    u8 pad20[0x24];
    void* unk44;
};

struct Ctx {
    Arg3* unk0;
    Heap* unk4;
    u8 pad8[0x15];
    u8 unk1D;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void fn_80010D5C(Heap* p, void* q, unsigned int mode);
void fn_8001133C(Heap* p, void* q, Vec2* v);
void fn_80011528(Heap* p, void* q, float f);
void fn_80010F70(Heap* p, void* q, s32 a, u8 b);
}

extern const f32 lbl_27_rodata_D18;
extern u8 lbl_804207A0[];
extern u8 lbl_80420768[];

inline void initCircle(Heap* h, void* arg, float value) {
    h->unk18 = 1;
    fn_80011528(h, arg, value);
}

extern "C" void fn_27_A6A54(Ctx* self, void* arg1, u8 arg2, Arg3* arg3,
                              s32 arg4, void* arg5) {
    Vec2 v;
    Heap* h;
    s32 t = arg3->unk0;

    if (t == 1)
        goto block9;
    if (t < 1) {
        if (t >= 0)
            goto block6;
        goto tail;
    }
    if (t == 5)
        goto block9;
    if (t < 5)
        goto block6;
    goto tail;

block6:
    h = (Heap*)__nw__FUlQ25Heaps8HeapType(0x68, arg4);
    if (h != 0) {
        fn_80010D5C(h, arg1, 0);
        h->unk44 = lbl_804207A0;
        h->unk18 = 0;
        v.x = lbl_27_rodata_D18;
        v.y = lbl_27_rodata_D18;
        fn_8001133C(h, arg1, &v);
    }
    self->unk4 = h;
    goto tail;

block9:
    h = (Heap*)__nw__FUlQ25Heaps8HeapType(0x54, arg4);
    if (h != 0) {
        fn_80010D5C(h, arg1, 0);
        h->unk44 = lbl_80420768;
        initCircle(h, arg1, lbl_27_rodata_D18);
    }
    self->unk4 = h;

tail:
    {
        u8 b = arg3->unk1;
        s32 a = arg3->unk4;
        h = self->unk4;
        h->bits.low = arg2;
        s32 c = arg3->unk8;
        self->unk4->unk1C_b[1] = b;
        self->unk4->unk8 = a;
        self->unk4->unkC = c;
        fn_80010F70(self->unk4, arg5, a, b);
    }
    self->unk4->flags.top = 0;
    self->unk0 = arg3;
    self->unk1D |= 0x40;
}
