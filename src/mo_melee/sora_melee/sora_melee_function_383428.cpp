#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

struct FnA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct FnB {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32 a, void* b);
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
    virtual int v16();
};

struct FnC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(u32 a, void* b);
    virtual void v5(u32 a, u32 b);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float v12(u32 a, void* b);
};

struct FnG {
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
    virtual float v12(u32 a);
};

struct FnE {
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
    virtual float v16();
};

struct Mid {
    char pad0[0x14];
    FnA* s1;
    char pad1[0x5c - 0x18];
    FnE* s5c;
    char pad2[0x64 - 0x60];
    FnC* s3;
    char pad3[0x70 - 0x68];
    FnB* s2;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Tabs {
    char pad0[0x94];
    s32 (*t94)[3];
    s32 (*t98)[3];
};

struct Top {
    char pad0[0x60];
    Obj* obj;
    char pad1[0x7f9c - 0x64];
    Tabs* tabs;
};

extern float lbl_27_rodata_7C0C;
extern float lbl_27_rodata_7C14;

extern "C" void fn_27_383428(Top* self, void* unused, s32 id) {
    Obj* o = self->obj;
    s32 idx;
    s32 ret;
    s32 var_r28;
    s32 var_r27;

    if (o->mid->s1->v3() == 5 || o->mid->s2->v16() == 0x11B) {
        return;
    }
    switch (id) {
    case 0x112:
        idx = 0;
        break;
    case 0x113:
        idx = 1;
        break;
    case 0x114:
        idx = 2;
        break;
    default:
        return;
    }
    ret = o->mid->s3->v4(0x10000049, o->mid);
    var_r28 = 1;
    var_r27 = 0;
    if (self->tabs->t94[ret][idx] == 1) {
        if (id == 0x112) {
            if (lbl_27_rodata_7C0C == o->mid->s3->v12(0x11000015, o->mid)) {
                var_r27 = 2;
            } else {
                var_r27 = 1;
            }
        } else {
            if (o->mid->s5c->v16() > lbl_27_rodata_7C14) {
                var_r27 = 2;
            } else {
                var_r27 = 1;
            }
        }
    }
    float a = reinterpret_cast<FnG*>(o->mid->s3)->v12(0x1100001A);
    if (a > soValueAccesser::getConstantFloat((soModuleAccesser*)o, 0xFA6, 0)) {
        float b = reinterpret_cast<FnG*>(o->mid->s3)->v12(0x11000017);
        float c = soValueAccesser::getConstantFloat((soModuleAccesser*)o, 0xFA7, 0);
        if (b > c) {
            var_r28 = 0;
        } else if (b < -c) {
            var_r28 = 2;
        }
    }
    o->mid->s3->v5(self->tabs->t98[var_r28][var_r27], 0x20000000);
    o->mid->s2->v3(0x122, o);
}
