#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct grCollision;

struct Obj68 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f10(Vec3f* out);
};

bool stRayCheck(Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d, bool e, grCollision* f, bool g, u8 h);

extern "C" bool fn_27_310F4(u8* self, Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d, bool e) {
    Vec3f tmp;
    Obj68* obj = *(Obj68**)(*(u8**)(self + 0xd8) + 0x68);
    obj->f10(&tmp);
    return stRayCheck(a, b, c, d, e, nullptr, false, 1);
}
