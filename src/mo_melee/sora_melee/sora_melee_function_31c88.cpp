#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

extern "C" const float lbl_27_rodata_450;
extern "C" u32 fn_80111CB0(void*, void*);

struct A { u8 pad[0x10]; };
struct B {
    u8 pad[0x54];
    u8 flags;
};
struct C {
    u8 pad[0x2C];
    u8 flags;
};

struct Bits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Local {
    A* a;
    B* b;
    C* c;
    u8 byte;
    Bits bits;
};

struct Vec4 {
    float x, y, z, w;
};

struct Id {
    u32 v;
};

struct Self {
    u8 pad[8];
    Id i0;
    Id i1;
    Id i2;
    float f[4];
    u8 b24;
    u8 b25;
};

extern "C" u8 fn_27_31C88(Self* self) {
    int valid = 0;
    Local l;
    l.a = 0;
    l.b = 0;
    l.c = 0;
    l.byte = 0;
    l.bits.hi = 0;

    int ok;
    if (self->i0.v == 0xFFFF) {
        ok = 0;
    } else {
        Id id;
        id = self->i0;
        if (fn_80111CB0(&id, &l.a) == 0) {
            ok = 0;
        } else {
            if (l.a && l.b && l.c)
                valid = 1;
            int enabled;
            if (valid && ((l.b->flags >> 4) & 1) && ((l.c->flags >> 7) & 1))
                enabled = 1;
            else
                enabled = 0;
            ok = enabled != 0;
        }
    }

    if (!ok) {
        Vec4 v;
        Id none;
        none.v = 0xFFFF;
        self->i0 = none;
        self->i1 = none;
        self->i2 = none;
        self->b24 = 0;
        v.x = lbl_27_rodata_450;
        v.y = lbl_27_rodata_450;
        self->f[0] = v.x;
        self->f[1] = v.y;
        v.z = lbl_27_rodata_450;
        v.w = lbl_27_rodata_450;
        self->f[2] = v.z;
        self->f[3] = v.w;
        self->b25 = 0;
    }
    return self->b24;
}
