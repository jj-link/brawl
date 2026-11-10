#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#include <nw4r/math.h>
#pragma force_active on

struct Vector { float x, y, z; };

struct Speed {
    float x, y;
    Speed() {}
    Speed(float a, float b) : x(a), y(b) {}
};

struct Accesser;

class Energy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void reset(int, Speed*, Vector*, Accesser*);
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Energy* getEnergy(int);
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(unsigned int);
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
    virtual int isFlag(unsigned int);
    virtual void onFlag(unsigned int);
    virtual void offFlag(unsigned int);
};

class ModuleC {
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
    virtual float get();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void f20();
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
    virtual void v30();
    virtual void set(float);
};

class ModuleD {
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
    virtual float get();
};

struct Modules {
    char pad0[0xc];
    ModuleC* moduleC;
    soGroundModule* other;
    char pad1[0x5c - 0x14];
    ModuleD* moduleD;
    char pad2[0x64 - 0x60];
    Work* work;
    char pad3[0x7c - 0x68];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const float lbl_94_rodata_28;
extern const char lbl_94_data_9848[], lbl_94_data_9934[], lbl_94_data_4570[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vector* fn_94_94E0(Vector*, float, float, float);
void fn_27_89DAC(int, Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
}

extern "C" void fn_94_F180(void*, Accesser* a) {
    float* data = *reinterpret_cast<float**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3)) + 0x80);

    if (a->modules->work->isFlag(0x22000010) != 0) {
        a->modules->work->offFlag(0x22000010);

        Energy* e1 = static_cast<Energy*>(__dynamic_cast(
            a->modules->kinetic->getEnergy(0), 0,
            lbl_94_data_9848, lbl_94_data_4570, 1));
        Speed s1(lbl_94_rodata_28, lbl_94_rodata_28);
        Vector v1;
        e1->reset(4, &s1,
            fn_94_94E0(&v1, lbl_94_rodata_28, lbl_94_rodata_28, lbl_94_rodata_28), a);
        ((unsigned char*)e1)[5] |= 0x80;

        Energy* e2 = static_cast<Energy*>(__dynamic_cast(
            a->modules->kinetic->getEnergy(2), 0,
            lbl_94_data_9934, lbl_94_data_4570, 1));
        float ret = a->modules->moduleC->get();
        float s8 = *data * ret;
        Speed s2(s8, lbl_94_rodata_28);
        Vector v2;
        e2->reset(0, &s2,
            fn_94_94E0(&v2, lbl_94_rodata_28, lbl_94_rodata_28, lbl_94_rodata_28), a);
        *(float*)((char*)e2 + 0x40) = lbl_94_rodata_28;
        ((unsigned char*)e2)[5] |= 0x80;

        fn_27_89DAC(3, a);
        a->modules->other->setCorrect((soGroundShapeImpl::CorrectKind)5, 0);
    }

    if (a->modules->work->isFlag(0x22000011) == 0) {
        float f31 = (float)(double)nw4r::math::FAbs(a->modules->moduleD->get());
        if (f31 > getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xFA8, 0)) {
            a->modules->moduleC->set(lbl_94_rodata_28);
            a->modules->moduleC->f20();
        }
    }
}
