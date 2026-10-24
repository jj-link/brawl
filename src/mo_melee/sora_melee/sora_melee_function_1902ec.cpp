#include <types.h>
#pragma force_active on

class Inner8 {
public:
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(void*, f32);
};

class Inner64 {
public:
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
    virtual void v13(u32, f32);
};

struct Base9C {
    s32 a;
    s32 b;
};

class Inner9C : public Base9C {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Holder {
    char pad0[8];
    Inner8* inner8;
    char pad1[0x58];
    Inner64* inner64;
    char pad2[0x34];
    Inner9C* inner9C;
};

struct Owner {
    char pad[0xD8];
    Holder* holder;
};

extern "C" const f32 lbl_27_rodata_2640;
extern "C" const f32 lbl_27_rodata_2648;

struct Local {
    s32 a;
    f32 b;
    f32 c;
    s8 d;
    s8 e;
    s8 f;
    s8 g;
};

extern "C" void fn_27_1902EC(void* unused, Owner* self) {
    f32 b = lbl_27_rodata_2640;
    f32 c = lbl_27_rodata_2648;
    s32 id = 0xA4;
    Inner8* p = self->holder->inner8;

    Local local;
    local.a = id;
    local.b = b;
    local.c = c;
    local.d = 0;
    local.e = 0;
    local.f = 0;
    local.g = 0;

    p->v30(&local, b);
    self->holder->inner9C->v6();
    self->holder->inner64->v13(0x21000007, lbl_27_rodata_2648);
}
