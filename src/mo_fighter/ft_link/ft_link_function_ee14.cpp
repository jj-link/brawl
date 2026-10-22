#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

namespace {
struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

struct Work {
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
    virtual int getInt(int);
};

struct Modules {
    char p[0xc];
    void* posture;
    char q[0x54];
    Work* work;
    char r[0x14];
    Kinetic* kinetic;
};

struct Access {
    char p[0xd8];
    Modules* modules;
};
}

extern "C" {
extern const char lbl_93_data_3018[], lbl_93_data_30FC[], lbl_93_data_80B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_15FBC8(int);
void fn_27_15CF5C(void*, float);
}

extern "C" void fn_93_EE14(void*, int, void*, soModuleAccesser* accesser) {
    Access* a = reinterpret_cast<Access*>(accesser);
    fn_27_15FBC8(0);
    void* energy1 = a->modules->kinetic->getEnergy(1);
    char* energy = static_cast<char*>(__dynamic_cast(energy1, 0, lbl_93_data_3018, lbl_93_data_30FC, 1));
    if (a->modules->work->getInt(0x22000010) == 0) {
        *(float*)(energy + 0x0c) = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
    }
    float f = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
    float g = soValueAccesser::getConstantFloat(accesser, 0xbcf, 0);
    *(float*)(energy + 0x10) = -g * f;
    void* energy2 = a->modules->kinetic->getEnergy(2);
    char* energy3 = static_cast<char*>(__dynamic_cast(energy2, 0, lbl_93_data_80B0, lbl_93_data_30FC, 1));
    *(float*)(energy3 + 0x3c) = soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
    float h = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
    fn_27_15CF5C(energy3, h);
}
