#include <so/so_value_accesser.h>
#include <mt/mt_common.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Vec2 { float x; float y; };
struct Energy {
    virtual void f0();
    virtual void f1();
    virtual Vec2 getSpeed();
};
struct Kinetic {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual Energy* getEnergy(int);
};

extern "C" void fn_27_16AD28(void*, soModuleAccesser*);
extern "C" float lbl_27_rodata_21A4;
extern "C" float lbl_27_rodata_21A8;

extern "C" void fn_27_16C98C(void* self, soModuleAccesser* object) {
    fn_27_16AD28(self, object);
    float threshold = soValueAccesser::getConstantFloat(object, 0xcd1, 0);
    Vec2 v = ((Kinetic*)object->m_enumerationStart->m_kineticModule)->getEnergy(4)->getSpeed();
    float x = v.x;
    float y = v.y;
    float square = x * x + y * y;
    float length;
    if ((float)(double)nw4r::ut::Abs(square) <= lbl_27_rodata_21A8)
        length = lbl_27_rodata_21A4;
    else
        length = square * rsqrtf(square);
    int result;
    if (length < threshold) {
        result = -1;
    } else {
        soEffectModule* effect = object->m_enumerationStart->m_effectModule;
        threshold = soValueAccesser::getConstantFloat(object, 0xcd2, 0);
        result = effect->reqContinual((EfID)12, threshold, soValueAccesser::getConstantInt(object, 0x59e0, 0), true, -1);
    }
    object->m_enumerationStart->m_workManageModule->setInt(result, 0x20000000);
    object->m_enumerationStart->m_groundModule->selectCliffHangData(1, 0);
}
