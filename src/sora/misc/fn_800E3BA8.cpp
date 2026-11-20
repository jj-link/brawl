#include <types.h>
#include <mt/mt_prng.h>
#include <mu/mu_object.h>

#pragma force_active on

struct Elem {
    s32 x;
    f32 y;
    f32 z;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(f32);
};

extern mtRand lbl_805A0420;
extern f32 lbl_805A23B0;
extern f32 lbl_805A23B4;
extern f32 lbl_805A23C0;
extern f32 lbl_805A23F0;
extern f32 lbl_805A2444;

extern "C" void fn_800B6838(MuObject*, const Vec3f*);
extern "C" void fn_800E1588(void*, u32, s32, s32);

extern "C" void fn_800E3BA8(u8* self) {
    f32 v[3];
    u8* c;
    u8* d;
    u8* b;
    Elem* p;
    Elem* base;
    s32 i;
    s32 a;
    f32 fd;
    f32 fc;
    f32 fb;
    f32 fa;
    s32 t;

    v[0] = lbl_805A23B0;
    v[1] = lbl_805A23B0;
    v[2] = lbl_805A23B0;
    base = (Elem*)(self + 0x12c);
    fa = lbl_805A23B4;
    fb = lbl_805A23F0;
    fc = lbl_805A23C0;
    fd = lbl_805A2444;
    p = base;
    for (i = 0; i < 19; i++) {
        p->x = (s32)(fa * lbl_805A0420.randf());
        p->y = fb * lbl_805A0420.randf() - fc;
        p->z = fd * lbl_805A0420.randf();
        p++;
    }
    {
        u8* e = self + 8;
        for (i = 2; i < 6; i++) {
            ((Object_vptr_0*)(*(char**)(*(char**)(*(char**)(e + 0x28) + 0x14) + 0xC)))->slot8(lbl_805A23B0);
            e += 4;
        }
    }
    b = self + 8;
    for (i = 2; i < 6; i++) {
        ((MuObject*)(*(char**)(b + 0x28)))->setFrameNode(lbl_805A23B0);
        b += 4;
    }
    c = self;
    d = self + 0xFC;
    for (i = 0; i < 4; i++) {
        fn_800B6838(*(MuObject**)(c + 0x30), (const Vec3f*)d);
        c += 4;
        d += 0xC;
    }
    t = *(s32*)(self + 0x18);
    *(s32*)(self + 0x1C) = t;
    fn_800E1588(self, t, 1, 1);
    i = (s32)(self + 0x18);
    for (a = 6; a < 24; a++) {
        fn_800B6838(*(MuObject**)(i + 0x28), (const Vec3f*)v);
        i += 4;
    }
    *(s32*)((u8*)base + 0xe4) = 0x3c;
}
