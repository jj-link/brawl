#pragma force_active on

typedef unsigned int u32;
typedef int s32;

#define VF(n) virtual void v##n();

struct KindBase {
    char data[0x3c];
};

struct KindObj : KindBase {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
    VF(10) VF(11) VF(12) VF(13) VF(14) VF(15) VF(16) VF(17) VF(18) VF(19)
    VF(20) VF(21) VF(22) VF(23) VF(24) VF(25) VF(26) VF(27) VF(28) VF(29)
    VF(30) VF(31) VF(32) VF(33) VF(34) VF(35) VF(36) VF(37) VF(38) VF(39)
    virtual s32 f40();
};

struct ModuleC {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8)
    VF(9) VF(10) VF(11) VF(12) VF(13)
    virtual float f14(u32 x);
};

struct ModuleD {
    VF(0) VF(1) VF(2) VF(3) VF(4)
    virtual s32 f5(s32 a, s32 b, s32 c, s32 d);
    VF(6) VF(7) VF(8) VF(9) VF(10) VF(11) VF(12) VF(13) VF(14)
    VF(15) VF(16) VF(17) VF(18) VF(19)
    virtual void f20(s32 a, s32 b, void* c);
};

struct ModuleE {
    VF(0) VF(1) VF(2) VF(3)
    virtual s32 f4(u32 x);
    virtual void f5(s32 a, u32 b);
    VF(6) VF(7) VF(8)
    virtual void f9(s32 a, u32 b);
};

struct Modules {
    char pad0[8];
    ModuleC* c;
    char pad1[0x44];
    ModuleD* d;
    char pad2[0x10];
    ModuleE* e;
};

struct Owner {
    char pad0[8];
    KindObj* kind;
    char pad1[0xcc];
    Modules* mod;
};

extern "C" int fn_27_1922CC(void*, u32);
extern s32 lbl_27_data_9C76C[];
extern s32 lbl_27_data_9C750[];

extern "C" void fn_27_3A1D00(void*, Owner* owner) {
    s32 r28 = owner->mod->e->f4(0x20000000);
    s32 r31 = owner->mod->e->f4(0x20000003);
    s32 kind = owner->kind->f40();
    s32 local;
    if (kind == 5) {
        local = (s32)owner->mod->c->f14(0x293);
    } else {
        local = (s32)owner->mod->c->f14(0x1cf);
    }
    if (r28 == local * r31) {
        s32 val = owner->mod->e->f4(0x20000004);
        if (val >= 0) {
            owner->mod->d->f20(val, 0, owner->mod);
        }
        s32 data_result;
        if (kind == 5) {
            data_result = owner->mod->d->f5(lbl_27_data_9C76C[r31], 0, 0, 0);
        } else {
            data_result = owner->mod->d->f5(lbl_27_data_9C750[r31], 0, 0, 0);
        }
        owner->mod->e->f5(data_result, 0x20000004);
        if (r31 < fn_27_1922CC(owner, 0x5dc0) - 1) {
            owner->mod->e->f9(1, 0x20000003);
        }
    }
}
