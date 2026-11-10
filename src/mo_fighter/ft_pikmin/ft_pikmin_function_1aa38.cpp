#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    float x, y;
};

extern "C" Vec3* fn_113_A1D0(Vec3*, float, float, float);
extern float lbl_113_rodata_5C;

class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual void fn_113_1C074();
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054();
    virtual void fn_113_1C04C();
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C();
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual void fn_113_1C014();
    virtual void fn_113_1C004(Vec3*, short*);
    virtual void fn_113_1BFF4(Vec3*, short*);
    virtual void fn_113_1BFE4();
};

struct Face {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50(int);
};

struct ModC {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
};

struct Mod18 {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14(int, int);
    virtual void f18();
    virtual void f1c();
    virtual void f20(int);
    virtual void f24(int);
    virtual void f28();
    virtual void f2c(int);
    virtual void f30(int);
};

struct Mods;

struct BC {
    char pad[8];

    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual int f28(Mods*);
    virtual int f2c();
};

struct Mods {
    char pad0[0xc];
    ModC* c;
    char pad10[8];
    Mod18* m18;
    char pad1c[0x48];
    Face* face;
    char pad68[0x14];
    Class_7FE8* m7c;
    char pad80[0x3c];
    BC* bc;
};

struct Inner {
    char pad[0xd8];
    Mods* mods;
};

struct Self {
    char pad[0x60];
    Inner* inner;
};

extern "C" int fn_113_1AA38(Self* self, Vec2* a, Vec2* b) {
    self->inner->mods->face->f50(0x12000006);
    self->inner->mods->c->f34();
    self->inner->mods->c->f54();

    BC* bc = self->inner->mods->bc;
    int value = bc->f2c();
    self->inner->mods->m18->f14(value, 1);
    self->inner->mods->m18->f20(value);

    Mods* mods = self->inner->mods;
    BC* bc2;
    Mod18* mod;
    int v = (bc2 = mods->bc, mod = mods->m18, bc2)->f28(mods);
    mod->f24(v);

    self->inner->mods->m18->f2c(-1);
    self->inner->mods->m18->f30(-1);

    if (lbl_113_rodata_5C != a->x || lbl_113_rodata_5C != a->y) {
        short flag = 1;
        Class_7FE8* obj = self->inner->mods->m7c;
        Vec3 v2;
        obj->fn_113_1C004(
            fn_113_A1D0(&v2, a->x, a->y, lbl_113_rodata_5C), &flag);
    }

    if (lbl_113_rodata_5C != b->x || lbl_113_rodata_5C != b->y) {
        short flag = 1;
        Class_7FE8* obj = self->inner->mods->m7c;
        Vec3 v2;
        obj->fn_113_1BFF4(
            fn_113_A1D0(&v2, b->x, b->y, lbl_113_rodata_5C), &flag);
    }

    return 0;
}
