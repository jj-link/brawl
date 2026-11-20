#include <types.h>
#pragma force_active on

struct Vec2 {
    f32 x;
    f32 y;
};

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Params {
    char pad[0x10];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
};

struct FtData {
    char pad[0x90];
    Params* params;
};

struct Module {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void* get(int);
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void call(int, void*, void*);
};

struct Holder {
    char pad[0x7C];
    Module* module;
};

struct Self {
    char pad[0xD8];
    Holder* holder;
};

struct EnergyA {
    char pad[0x20];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2c;
};

struct EnergyB {
    char pad[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1c;
};

struct Locals {
    f32 dead0[2];
    f32 dead1[2];
    f32 v2[2];
    f32 v1[2];
    f32 z2[3];
    f32 z1[3];
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern char g_ftCommonDataAccesser[];
extern char lbl_27_data_320E0[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern f32 lbl_27_rodata_2640;
}

extern "C" void fn_27_190A8C(void* arg0) {
    Self* self = (Self*)arg0;
    Module* module = self->holder->module;
    EnergyA* r29 = (EnergyA*)__dynamic_cast(module->get(4), 0, lbl_27_data_320E0, lbl_27_data_CDF8, 1);
    EnergyB* r30 = (EnergyB*)__dynamic_cast(module->get(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    FtData* d = (FtData*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 9);
    Params* params = d->params;
    f32 f31 = params->a;
    f32 f30 = params->b;
    f32 f29 = params->c;
    f32 f28 = params->d;
    module->call(0x1f, arg0, params);

    Locals l;
    l.v1[1] = f30;
    l.z1[0] = lbl_27_rodata_2640;
    l.z1[1] = lbl_27_rodata_2640;
    l.z1[2] = lbl_27_rodata_2640;
    l.v1[0] = lbl_27_rodata_2640;
    fn_27_89D08(1, arg0, 0, (Vec2*)&l.v1[0], (Vec3*)&l.z1[0]);

    l.v2[0] = f31;
    l.z2[0] = lbl_27_rodata_2640;
    l.z2[1] = lbl_27_rodata_2640;
    l.z2[2] = lbl_27_rodata_2640;
    l.v2[1] = lbl_27_rodata_2640;
    fn_27_89D08(4, arg0, 2, (Vec2*)&l.v2[0], (Vec3*)&l.z2[0]);

    f32 zero = lbl_27_rodata_2640;
    r29->unk28 = f31;
    r29->unk2c = zero;
    r29->unk20 = f29;
    r29->unk24 = zero;
    r30->unk10 = f28;
    r30->unk1c = f30;
    r30->unk14 = f30;
    r30->unk18 = zero;
    l.dead1[0] = f31;
    l.dead1[1] = zero;
    l.dead0[0] = f29;
    l.dead0[1] = zero;
}
