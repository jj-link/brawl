#include <types.h>
#pragma force_active on

struct Vec3f;

extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_104C;

class ObjA {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(f32);
};

class ObjB {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(s32, void*);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

class ObjC {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(u32, u32, f32*, f32*, f32*, f32*, u32, u32, f32);
    virtual void slot9();
    virtual void slot10();
};

struct Inner {
    unsigned char pad0[0xc];
    ObjA* a;
    unsigned char pad1[0x60];
    ObjB* b;
    unsigned char pad2[0x14];
    ObjC* c;
};

struct Owner {
    unsigned char pad[0xd8];
    Inner* inner;
};

class Fighter {
public:
    void warp(Vec3f* arg0, f32 arg1, u32 arg2);

    unsigned char pad[0x60];
    Owner* owner;
};

void Fighter::warp(Vec3f* arg0, f32 arg1, u32 arg2) {
    Owner* o = owner;
    o->inner->a->slot3();
    o->inner->a->slot10(arg1);
    o->inner->b->slot3(0xe, o);
    if (arg2 == 1) {
        f32 values[12];
        values[0] = lbl_27_rodata_1048;
        values[1] = lbl_27_rodata_1048;
        values[2] = lbl_27_rodata_1048;
        values[3] = lbl_27_rodata_1048;
        values[4] = lbl_27_rodata_1048;
        values[5] = lbl_27_rodata_1048;
        values[6] = lbl_27_rodata_1048;
        values[7] = lbl_27_rodata_1048;
        values[8] = lbl_27_rodata_1048;
        values[9] = lbl_27_rodata_1048;
        values[10] = lbl_27_rodata_1048;
        values[11] = lbl_27_rodata_1048;
        o->inner->c->slot8(0x0104004E, 0x12E, &values[9], &values[6], &values[3], &values[0], 0, 0, lbl_27_rodata_104C);
    }
}
