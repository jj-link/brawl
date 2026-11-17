#pragma peephole on
#pragma optimization_level 1
#pragma scheduling off
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma force_active on
#include <nw4r/math/math_arithmetic.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>

extern "C" {
extern const unsigned char lbl_110_data_5F8[];
extern const unsigned char lbl_110_data_212C[];
extern const unsigned char lbl_110_data_62B8[];
extern const float lbl_110_rodata_50;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_110_8C60(void*);
void* fn_110_1EF78(void*);
}

struct Inner {
    char pad[0xc];
    float threshold;
};
struct Outer {
    char pad[8];
    Inner* inner;
};

extern "C" void fn_110_E500(void*, soModuleAccesser* self, int id) {
    if (id == 0x12e) {
        soControllerModule* ctrl = self->m_enumerationStart->m_controllerModule;
        soPostureModule* posture = self->m_enumerationStart->m_postureModule;
        StageObject* obj = self->m_stageObject;
        Inner* inner;
        if (obj->soGetSubKind() == 0x15) {
            inner = ((Outer*)fn_110_8C60(__dynamic_cast(obj, 0x3c, lbl_110_data_5F8, lbl_110_data_212C, 1)))->inner;
        } else {
            inner = ((Outer*)fn_110_1EF78(__dynamic_cast(obj, 0x3c, lbl_110_data_62B8, lbl_110_data_212C, 1)))->inner;
        }
        float lr = posture->getLr();
        float stick = ctrl->getStickX();
        if (nw4r::math::FAbs(stick) >= inner->threshold) {
            float stickSign = (float)(stick < lbl_110_rodata_50 ? -1 : 1);
            float lrSign = (float)(lr < lbl_110_rodata_50 ? -1 : 1);
            if (lrSign != stickSign) {
                posture->reverseLr();
            }
        }
    }
}