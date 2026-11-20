#include <types.h>
#pragma force_active on

struct FPair {
    f32 x;
    f32 y;
};

struct Src1 {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    u16 h10;
    u16 h12;
    s32 w14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
};

struct Src2 {
    union {
        s32 i;
        f32 f;
    } v[6];
};

struct Obj60 {
    char pad0[0x18];
    s32 unk18;
    u8 unk1C;
    char pad1[0x44 - 0x1D];
    void* unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
};

struct Dst {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    char pad1[0xC];
    unsigned int reserved : 24;
    unsigned int kind : 8;
};

struct SrcB {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80010D5C(void* p, const FPair* q, unsigned int mode);
extern "C" void OSReport(const char* fmt, ...);
extern const f32 lbl_27_rodata_38F0;
extern char lbl_27_data_4C218[];
extern char lbl_80420730[];

class Object_vptr_4_base {
public:
    char pad[0x4];
};

class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Dst* slot2();
    virtual void slot3();
    virtual void slot4();
    virtual SrcB* slot5();
    virtual void slot6(void* obj);

    char pad8[0xC];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u16 unk24;
    u16 unk26;
    s32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
};

extern "C" void fn_27_236220(Object_vptr_4* arg0, Src1 arg1, Src2 arg2) {
    f32 f24, f20, f1C, f18;
    s32 w14;
    u16 h12, h10;
    s32 aC, a8, a4, t;
    t = arg1.w0;
    a4 = arg1.w4;
    a8 = arg1.w8;
    aC = arg1.wC;
    h10 = arg1.h10;
    h12 = arg1.h12;
    w14 = arg1.w14;
    f18 = arg1.f18;
    f1C = arg1.f1C;
    f20 = arg1.f20;
    f24 = arg1.f24;
    arg0->unk14 = t;
    arg0->unk18 = a4;
    arg0->unk1C = a8;
    arg0->unk20 = aC;
    arg0->unk24 = h10;
    arg0->unk26 = h12;
    arg0->unk28 = w14;
    arg0->unk2C = f18;
    arg0->unk30 = f1C;
    arg0->unk34 = f20;
    arg0->unk38 = f24;
    switch (t) {
    case 2: {
        Obj60* obj = (Obj60*)__nw__FUlQ25Heaps8HeapType(0x60, 0xF);
        if (obj != 0) {
            FPair pair;
            pair.x = lbl_27_rodata_38F0;
            pair.y = lbl_27_rodata_38F0;
            fn_80010D5C(obj, &pair, 1);
            obj->unk44 = lbl_80420730;
            obj->unk18 = 2;
        }
        *(Src2*)&obj->unk48 = arg2;
        OSReport(lbl_27_data_4C218, arg2.v[0].f, arg2.v[1].f, arg2.v[2].f, arg2.v[3].f, arg2.v[4].f, arg2.v[5].f);
        obj->unk1C = obj->unk1C | 0x80;
        arg0->slot6(obj);
        break;
    }
    default:
        return;
    }
        Dst* d = arg0->slot2();
        if (d != 0) {
            SrcB* s = arg0->slot5();
            if (s != 0) {
                d->kind = 2;
                *(u8*)((char*)d + 0x1D) = (u8)s->unk4;
                d->unk8 = s->unk8;
                d->unkC = s->unkC;
            }
        }
}
