#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    u8 pad[0x30];
    u32 hi : 24;
    u32 lo : 8;
};

struct Inner {
    virtual void v0();
    virtual Obj* v1();
    virtual void v2();
    virtual void v3();
};

struct Outer {
    u8 pad[0x48];
    Inner* m_inner;
};

extern "C" void fn_27_6D9C8(Outer* self, int unused, u32 flag) {
    Obj* o = self->m_inner->v1();
    if (flag == 1) {
        o->hi |= 1;
    } else {
        o->hi &= ~1u;
    }
    if (flag == 1) {
        o->hi |= 2;
    } else {
        o->hi &= ~2u;
    }
    if (flag == 1) {
        o->hi |= 8;
    } else {
        o->hi &= ~8u;
    }
    if (flag == 1) {
        o->hi |= 0x80;
    } else {
        o->hi &= ~0x80u;
    }
    if (flag == 1) {
        o->hi |= 0x2000;
    } else {
        o->hi &= ~0x2000u;
    }
    if (flag == 1) {
        o->hi |= 0x4000;
    } else {
        o->hi &= ~0x4000u;
    }
}
