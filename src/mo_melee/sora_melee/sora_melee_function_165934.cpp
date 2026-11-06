#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>

#pragma force_active on

struct V2 {
    float x, y;
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30(float);
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual V2 fn_27_14D08(short*);
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual u32 fn_27_14B88(u32);
    virtual void fn_27_16A70(u32);
};

extern "C" const float lbl_27_rodata_2028[];

extern "C" void fn_27_165934(void*, soModuleAccesser* self) {
    const float* c = lbl_27_rodata_2028;
    float limit = 0.001f;
    short flag = 1;
    V2 speed = reinterpret_cast<Class_1250*>(
        self->m_enumerationStart->m_kineticModule)->fn_27_14D08(&flag);
    float x = speed.x;

    if (!reinterpret_cast<Class_1250*>(
            self->m_enumerationStart->m_workManageModule)
             ->fn_27_14B88(0x22000011)) {
        if ((float)(double)nw4r::math::FAbs(x) > limit) {
            reinterpret_cast<Class_1250*>(
                self->m_enumerationStart->m_motionModule)->fn_27_14A30(0.0f);
            reinterpret_cast<Class_1250*>(
                self->m_enumerationStart->m_workManageModule)
                ->fn_27_16A70(0x22000011);
        }
    } else {
        if ((float)(double)nw4r::math::FAbs(x) <= limit) {
            reinterpret_cast<Class_1250*>(
                self->m_enumerationStart->m_motionModule)->fn_27_14A30(1.0f);
        }
    }
}
