#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_1018[];

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int slot5(int, int, int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int slot11(int, int, float*, float*, float, int, int, int, int);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14(int, int, float);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(int, float);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38(int, float);
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55(int, int, int, int);
};

class Wrap {
    char pad[8];
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50(int);
};

struct Mods {
    char p0[0x38];
    Wrap* c;
    char p1[0x14];
    Object_vptr_0* d;
    char p2[8];
    Object_vptr_0* e;
    char p3[0x28];
    Object_vptr_0* f;
};

struct Ctrl {
    char pad[0xd8];
    Mods* mod;
};

struct Acc {
    char pad[0x60];
    Ctrl* ctrl;
};

extern "C" int fn_27_13BF9C(Acc* arg, u32 kind, float value) {
    const float* rd = lbl_27_rodata_1018;
    float high_b[3];
    float high_a[3];
    float low_a[3];
    float low_b[3];
    Ctrl* ctrl;
    Object_vptr_0* effect;
    Ctrl* initial = arg->ctrl;
    int r;
    initial->mod->c->c50(0);

    if (value < rd[12]) {
        if (kind == 1) {
            ctrl = arg->ctrl;
            ctrl->mod->d->slot5(0x12, 0, 0, 0);
            ctrl->mod->f->slot38(0x1f, rd[12]);

            low_a[0] = rd[12];
            low_a[1] = rd[12];
            low_a[2] = rd[12];
            low_b[0] = rd[12];
            low_b[1] = rd[12];
            low_b[2] = rd[12];

            effect = ctrl->mod->f;
            float scale = soValueAccesser::getConstantFloat(
                (soModuleAccesser*)ctrl, 0xbe9, 0);
            return effect->slot11(0x36, 0, low_b, low_a, scale, 0, 0, 0, -1);
        }
    } else {
        Ctrl* ctrl = initial;
        ctrl->mod->e->slot55(0xd, 0, 0, -1);
        r = ctrl->mod->d->slot5(0x3b, 0, 0, 0);
        if (r >= 0) {
            ctrl->mod->d->slot14(r, 0, rd[15]);
            ctrl->mod->d->slot17(r, rd[36]);
        }

        high_a[0] = rd[12];
        high_a[1] = rd[12];
        high_a[2] = rd[12];
        high_b[0] = rd[12];
        high_b[1] = rd[12];
        high_b[2] = rd[12];
        return ctrl->mod->f->slot11(0x61, -2, high_b, high_a, rd[13], 0, 0, 0, -1);
    }
    return 0;
}
