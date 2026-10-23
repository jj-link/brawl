#include <types.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;

    Vec3(const Vec3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
};

struct ResultA {
    unsigned char pad[0x44];
    Vec3 value;
};

struct ResultB {
    unsigned char pad[0x88];
    unsigned int val;
};

struct IfaceA {
    virtual void vf0() = 0;
    virtual ResultA* vf1(unsigned int) = 0;
};

struct IfaceB {
    virtual void vf0() = 0;
    virtual ResultB* vf1(unsigned int) = 0;
};

struct ObjC {
    unsigned char pad[0x30];

    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual Vec3 get() = 0;
};

struct Work {
    unsigned char pad[0x30];
    IfaceB* field30;
    IfaceA* field34;
    unsigned char pad2[0x30];
    unsigned int field68;
};

extern "C" ObjC* fn_27_36028(void*, unsigned int, unsigned int);

extern "C" Vec3 fn_27_3AC30(
    Work* arg1, unsigned int arg2, unsigned int arg3)
{
    if (arg3 == 1U) {
        ResultA* r = arg1->field34->vf1(arg2);
        return r->value;
    } else {
        ResultB* rb = arg1->field30->vf1(arg2);
        ObjC* obj = fn_27_36028(&arg1->field68, arg2, rb->val);
        return obj->get();
    }
}
