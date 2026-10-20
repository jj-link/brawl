#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Vec3f get();
};

struct Flag {
    u8 value;
    u8 pad[3];
};

extern "C" {
void fn_27_408BC(Flag* flag, u32 p2, Vec3f* vec, u32 p4, u32 p5, u32 p6);
void fn_27_410F0(Flag* flag, u32 p2, Vec3f* vec, u32 p4);
}

extern "C" void fn_27_41310(void* unused, Obj* obj, u32 a, u32 b, u32 c, u32 d) {
    Flag flag1;
    Flag flag2;
    const Vec3f& vec = obj->get();
    flag1.value = 0;
    fn_27_408BC(&flag1, d, const_cast<Vec3f*>(&vec), b, c, a);
    flag2.value = 0;
    fn_27_410F0(&flag2, d, const_cast<Vec3f*>(&vec), a);
}
