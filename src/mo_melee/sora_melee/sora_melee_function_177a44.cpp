#pragma force_active on
#include <types.h>

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" char lbl_27_data_13690[];
extern "C" char lbl_27_data_CDF8[];
extern "C" const float lbl_27_rodata_2314;

struct Vec2 { float x; float y; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int, float);
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(u32);
};

struct Modules {
    char p[0xc];
    Object_vptr_0* posture;
    char p1[0x54];
    Object_vptr_0* work;
    char p2[0x14];
    Object_vptr_0* kinetic;
};
struct Obj { char p[0xd8]; Modules* modules; };

extern "C" void fn_27_177A44(void*, Obj* obj) {
    Object_vptr_0* w = obj->modules->work;
    if (w->slot17(0x22000010)) {
        float rate = obj->modules->posture->slot9();
        float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(obj, 0xbd5, 0);
        Vec2 v;
        v.x = c * rate;
        v.y = lbl_27_rodata_2314;
        void* e = obj->modules->kinetic->slot6(2, v.x);
        char* r = (char*)__dynamic_cast(e, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
        *(float*)(r + 8) = v.x;
        *(float*)(r + 12) = v.y;
    }
}