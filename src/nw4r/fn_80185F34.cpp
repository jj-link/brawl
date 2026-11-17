#include <nw4r/math/math_types.h>
#pragma force_active on

using nw4r::math::VEC2;

class Class_8046585C {
public:
    virtual void fn_801858D0();
    virtual int fn_80187CEC(int, unsigned int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
};

struct Rect {
    float x, y, z, w;
};

struct Self {
    char pad0[0x28];
    Class_8046585C* obj;
    char pad2c[0x20];
    float x, y;
    char pad54[0x80];
    float a, b, c, d;
    unsigned int data[4];
    char padf4;
    unsigned char flag;
    char padf6[2];
    int value;
};

extern "C" int fn_8018C3FC(unsigned int*, unsigned int);
extern "C" void fn_8018C4B8(int, int);
extern "C" void fn_8018CAFC(const VEC2&, const VEC2&, unsigned char, int,
                            unsigned int*, unsigned int);

extern "C" void fn_80185F34(Self* self, const VEC2* pos, const Rect* rect, unsigned int n) {
    int v = self->obj->fn_80187CEC(fn_8018C3FC(self->data, n), n);
    fn_8018C4B8(v, self->flag);
    unsigned int* p = v ? self->data : 0;
    int value = self->value;
    unsigned char flag = self->flag;
    float px, py, x1, ty, y1;
    py = self->y;
    y1 = rect->z;
    px = self->x;
    x1 = rect->x;
    ty = self->c + (py - y1);
    ty -= rect->w;

    fn_8018CAFC(
        VEC2(pos->x + x1 - self->a, pos->y + y1 - self->c),
        VEC2(self->b + ((self->a + (px - x1)) - rect->y),
             self->d + ty),
        flag, value, p, n);
}
