#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_121_22F8();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(int);
};

struct Modules {
    char p[0x64];
    Object_vptr_0* work;
    char r[0x14];
    Object_vptr_0* kinetic;
};

struct Access {
    char p[0xd8];
    Modules* modules;
};

extern "C" {
extern const char lbl_121_data_3110[], lbl_121_data_31F4[], lbl_121_data_81B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_15FBC8(int);
void fn_27_15CF5C(void*, float);
}

extern "C" void fn_121_EDCC(void*, int, void*, soModuleAccesser* accesser) {
    Access* a = reinterpret_cast<Access*>(accesser);
    fn_27_15FBC8(0);
    void* energy1 = a->modules->kinetic->slot6(1);
    char* energy = static_cast<char*>(__dynamic_cast(energy1, 0, lbl_121_data_3110, lbl_121_data_31F4, 1));
    if (a->modules->work->slot17(0x22000010) == 0) {
        *(float*)(energy + 0x0c) = soValueAccesser::getConstantFloat(accesser, 0xfa5, 0);
    }
    float f = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
    float g = soValueAccesser::getConstantFloat(accesser, 0xbcf, 0);
    *(float*)(energy + 0x10) = -g * f;
    void* energy2 = a->modules->kinetic->slot6(2);
    char* energy3 = static_cast<char*>(__dynamic_cast(energy2, 0, lbl_121_data_81B0, lbl_121_data_31F4, 1));
    *(float*)(energy3 + 0x3c) = soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
    float h = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
    fn_27_15CF5C(energy3, h);
}