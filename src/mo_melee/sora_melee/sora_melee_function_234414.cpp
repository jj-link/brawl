#include <types.h>

#pragma force_active on

struct Object_vptr_4_base {
    char pad[4];
};

class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual ~Object_vptr_4();
};

struct Vec2 {
    float x, y;
};

struct Params {
    u8 type, flag;
    u16 pad;
    float a, b, c, d;
};

struct Rect {
    float a, b, c, d;
};

struct Owner {
    char pad[0x18];
    Object_vptr_4* child;
    char pad2[0x10];
    char sub[1];
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" Object_vptr_4* fn_27_236E64(void*, void*, Rect*, bool);

extern "C" void fn_27_234414(Owner* self, const Vec2* a, const Vec2* b, u8 flag) {
    float by;
    float bx;
    float ay;
    float ax;
    ax = a->x;
    ay = a->y;
    bx = b->x;
    by = b->y;
    Params p;
    p.type = 1;
    p.flag = flag;
    p.pad = 0;
    p.a = ax;
    p.b = ay;
    p.c = bx;
    p.d = by;
    Rect r = { ax, bx, by, ay };
    Object_vptr_4* result =
        (Object_vptr_4*)__nw__FUlQ25Heaps8HeapType(0x28, 0xf);
    if (result) {
        result = fn_27_236E64(result, self->sub, &r, p.flag != 0);
    }
    if (self->child) {
        delete self->child;
    }
    self->child = result;
}
