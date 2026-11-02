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

class Inner50 {
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
};

class Inner64 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4(s32);
    virtual void v5(s32, s32);
    virtual void v6();
    virtual void v7(s32);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(u32);
};

struct Holder {
    char pad0[8];
    Inner8* inner8;
    char pad1[0x44];
    Inner50* inner50;
    char pad2[0x10];
    Inner64* inner64;
};

struct Owner {
    char pad[0xD8];
    Holder* holder;
};

extern "C" s32 fn_27_19075C(void*);
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

extern "C" void fn_27_1904B8(void* unused, Owner* self) {
    Holder* h = self->holder;
    Inner64* inner64 = h->inner64;
    Inner8* inner8 = h->inner8;
    s32 a = inner64->v4(0x20000000);
    s32 b = inner64->v4(0x20000001);
    s32 c = inner64->v4(0x20000002);
    inner64->v7(0x20000002);

    switch (a) {
    case 0:
        switch (b) {
        case 0:
            if (fn_27_19075C(self)) {
                Local local;
                local.a = 0xAA;
                local.b = lbl_27_rodata_2640;
                local.c = lbl_27_rodata_2648;
                local.d = 0;
                local.e = 0;
                local.f = 0;
                local.g = 0;
                inner8->v30(&local, lbl_27_rodata_2640);
                inner64->v7(0x20000001);
                inner64->v5(0x15, 0x20000002);
            }
            break;
        case 1:
            if (c >= 0x30) {
                Local local;
                local.a = 0xC6;
                local.b = lbl_27_rodata_2640;
                local.c = lbl_27_rodata_2648;
                local.d = 0;
                local.e = 0;
                local.f = 0;
                local.g = 0;
                inner8->v30(&local, lbl_27_rodata_2640);
                inner64->v7(0x20000001);
            }
            break;
        }
        break;
    case 1:
        switch (b) {
        case 0:
            if (c >= 0x27) {
                Local local;
                local.a = 0xC5;
                local.b = lbl_27_rodata_2640;
                local.c = lbl_27_rodata_2648;
                local.d = 0;
                local.e = 0;
                local.f = 0;
                local.g = 0;
                inner8->v30(&local, lbl_27_rodata_2640);
                inner64->v7(0x20000001);
                Inner50* p = self->holder->inner50;
                p->v18();
                inner64->v13(0x21000007);
                p->v2();
            }
            break;
        }
        break;
    }
}
