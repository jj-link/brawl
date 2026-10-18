#pragma force_active on
struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct soModuleAccesser;

struct Module {
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void* getEnergy(int);
};

struct Energy {
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void reset(int, const Vec2*, const Vec3*, soModuleAccesser*);
    unsigned char p04;
    unsigned char flags;
};

struct Modules {
    char pad[0x7c];
    Module* kinetic;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_26C0;
extern const float lbl_27_rodata_26B0;
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_27_1963F0(soModuleAccesser* a, float x, float y) {
    float speed =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xcaa, 0);
    float scaled = x * (
        lbl_27_rodata_26C0 -
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xcb1, 0));
    float product = scaled * speed;
    float base =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xcab, 0);
    speed = base + product;
    speed *=
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xcac, 0);

    if (speed >
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xcad, 0)) {
        speed =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xcad, 0);
    }

    Energy* e = static_cast<Energy*>(__dynamic_cast(
        a->modules->kinetic->getEnergy(4), 0,
        lbl_27_data_13690, lbl_27_data_CDF8, 1));

    Vec2 v = { speed * -y, lbl_27_rodata_26B0 };
    Vec3 w = {
        lbl_27_rodata_26B0,
        lbl_27_rodata_26B0,
        lbl_27_rodata_26B0
    };

    e->reset(11, &v, &w, a);
    e->flags |= 0x80;
}
}
