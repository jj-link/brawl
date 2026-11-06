#include <types.h>
#pragma force_active on

struct Vec {
    f32 x, y, z;
    Vec(f32 a, f32 b, f32 c) : x(a), y(b), z(c) {}
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(void*, int);
};

class Other {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, const Vec&, const Vec&, int, int, float);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
};

struct Modules {
    char pad0[0xC];
    Object_vptr_0* motion;
    char pad1[0x78];
    Other* other;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern float lbl_27_rodata_776C;
extern float lbl_27_rodata_7770;

extern "C" void fn_27_34167C(void*, Object* self, int kind) {
    if (kind != 2 && kind != 3) {
        Modules* modules = self->modules;
        Object_vptr_0* motion = modules->motion;
        Other* other = modules->other;
        Vec vec(lbl_27_rodata_776C, lbl_27_rodata_776C, lbl_27_rodata_776C);
        motion->slot15(&vec, 0);
        other->slot6(0x22, motion->slot4(),
                     Vec(lbl_27_rodata_776C, lbl_27_rodata_776C, lbl_27_rodata_776C),
                     0, -1, lbl_27_rodata_7770);
    }
}