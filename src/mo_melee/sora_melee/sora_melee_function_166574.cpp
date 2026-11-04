#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>

#pragma force_active on

struct V2 { float x, y; };

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual int fn_27_14134(u32);
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30(float);
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual float fn_27_14A60(u32);
    virtual V2 fn_27_14D08(short*);
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80(float, u32);
    virtual u32 fn_27_14B88(u32);
    virtual void fn_27_16A70(u32);
    virtual void fn_27_16AB8(u32);
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, u32, u32);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, u32, u32);
extern "C" const float lbl_27_rodata_2050;
extern "C" const float lbl_27_rodata_2054;

extern "C" void fn_27_166574(void*, soModuleAccesser* self) {
    if (reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_14B88(0x22000010) == 1) {
        float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC39, 0);
        float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xBC0, 0);
        limit = scale * limit;
        short flag = 1;
        V2 speed = reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_kineticModule)->fn_27_14D08(&flag);
        float x = speed.x;
        if (!reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_14B88(0x22000011)) {
            if ((float)(double)nw4r::math::FAbs(x) > limit) {
                reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_motionModule)->fn_27_14A30(lbl_27_rodata_2050);
                reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_16A70(0x22000011);
            }
        } else {
            if ((float)(double)nw4r::math::FAbs(x) <= limit) {
                reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_motionModule)->fn_27_14A30(lbl_27_rodata_2054);
                reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_16AB8(0x22000010);
            }
        }
    }
    if (!reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_14B88(0x22000013)) {
        int value = reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_14134(0x20000000);
        if (value > getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x59FA, 0))
            reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_16A70(0x22000013);
    }
    if (reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_14A60(0x21000006) > lbl_27_rodata_2050)
        reinterpret_cast<Class_1250*>(self->m_enumerationStart->m_workManageModule)->fn_27_14B80(lbl_27_rodata_2054, 0x21000006);
}
