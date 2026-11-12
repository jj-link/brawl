#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(float);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(unsigned long, float);
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual void slot38();
    virtual void slot39();
    virtual int slot40();
};

struct Modules {
    char pad[8];
    Object_vptr_0* motion;
    char padc[0x58];
    Object_vptr_0* work;
};

struct Accesser {
    char pad[8];
    Object_vptr_3c* object;
    char padc[0xcc];
    Modules* modules;
};

struct CommonData {
    char pad[0x3c];
    float* data;
};

extern "C" {
extern int g_ftCommonDataAccesser;
extern float lbl_27_rodata_20C0;
extern float lbl_27_rodata_20C8;

CommonData* fn_27_145534(void*, int);
float fn_27_168E78(Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);

void fn_27_169264(void*, Accesser* a) {
    float factor;
    float scale = *fn_27_145534(&g_ftCommonDataAccesser, a->object->slot40())->data;
    float delta;
    float base;
    float current = a->modules->work->slot12(0x21000004);
    float target = fn_27_168E78(a);
    base =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xbb9, 0) / scale;
    float add =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xbba, 0) / scale;
    delta = target * base;
    add = target > lbl_27_rodata_20C0 ? add : -add;
    delta += add;
    float ratio = current / target;

    if (ratio > lbl_27_rodata_20C0 && ratio < lbl_27_rodata_20C8) {
        factor = lbl_27_rodata_20C8 - ratio;
        delta *= factor *
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xc2e, 0);
    }

    float brake =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xbbc, 0) / scale;

    if (lbl_27_rodata_20C0 == target) {
        float absCurrent = (float)(double)nw4r::math::FAbs(current);
        float absBrake = (float)(double)nw4r::math::FAbs(brake);
        if (absBrake > absCurrent) {
            delta = -current;
        } else {
            if (current > lbl_27_rodata_20C0) {
                brake = -brake;
            }
            delta = brake;
        }
    } else if (delta > lbl_27_rodata_20C0) {
        if (current + delta > target) {
            delta = -brake;
            if (current + delta < target) {
                delta = target - current;
            }
        }
    } else if (current + delta < target) {
        delta = brake;
        if (current + brake > target) {
            delta = target - current;
        }
    }

    a->modules->work->slot13(0x21000004, current + delta);
    current =
        (float)(double)nw4r::math::FAbs(a->modules->work->slot12(0x21000004));
    a->modules->motion->slot7(current * a->modules->work->slot12(0x21000005));
}
}
