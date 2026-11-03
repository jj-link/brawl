#pragma force_active on
typedef unsigned int u32;

struct Mid;
struct Obj;

struct F14 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct F70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32, Obj*);
};

struct F84 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(u32, u32);
};

struct Mid {
    char pad0[0x14];
    F14* f14;
    char pad1[0x70 - 0x18];
    F70* f70;
    char pad2[0x84 - 0x74];
    F84* f84;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Top {
    char pad[0x60];
    Obj* obj;
};

extern "C" {
void fn_27_383338(Top* self) {
    Obj* o = self->obj;
    o->mid->f84->v16(0, 0);
    if (o->mid->f14->v3() == 5) {
        o->mid->f70->v3(0x11d, o);
        return;
    }
    if (o->mid->f14->v3() == 2) {
        o->mid->f70->v3(0x11a, o);
        return;
    }
    o->mid->f70->v3(0x119, o);
}
}
