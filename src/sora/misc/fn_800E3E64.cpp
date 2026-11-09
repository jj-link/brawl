#include <types.h>
#include <mu/mu_object.h>

#pragma force_active on

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

extern f32 lbl_805A23B0;
extern f32 lbl_805A23B4;
extern f32 lbl_805A23C0;

extern "C" void fn_800B6838(MuObject*, const Vec3f*);
extern "C" void fn_800E1588(void*, u32, s32, s32);

extern "C" void fn_800E3E64(u8* self) {
    s32 i;
    u8* f;
    u8* e;
    u8* c;
    u8* d;
    u8* b;
    u8* a;

    i = 2;
    a = self + 8;
    do {
        ((Object_vptr_0*)(*(char**)(*(char**)(*(char**)(a + 0x28) + 0x14) + 0xC)))->slot8(lbl_805A23B0);
        i++;
        a += 4;
    } while (i < 6);

    b = self + 8;
    i = 2;
    do {
        ((MuObject*)(*(char**)(b + 0x28)))->setFrameNode(lbl_805A23B0);
        i++;
        b += 4;
    } while (i < 6);

    c = self;
    d = self + 0xFC;
    for (i = 0; i < 4; i++, c += 4, d += 0xC) {
        fn_800B6838(*(MuObject**)(c + 0x30), (const Vec3f*)d);
    }

    i = 2;
    e = self + 8;
    do {
        ((MuObject*)(*(char**)(e + 0x28)))->setFrameNode(lbl_805A23B4);
        i++;
        e += 4;
    } while (i < 6);

    i = 2;
    f = self + 8;
    do {
        ((Object_vptr_0*)(*(char**)(*(char**)(*(char**)(f + 0x28) + 0x14) + 0xC)))->slot8(lbl_805A23C0);
        i++;
        f += 4;
    } while (i < 6);

    i = *(u32*)(self + 0x18);
    if ((u32)i == (*(u32*)(self + 0x1C) = (u32)i)) {
        fn_800E1588(self, i, 1, 0);
    }
    *(u32*)(self + 0x18) = i;
}
