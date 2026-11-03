#include <cm/cm_camera_controller.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern void* g_cmAIController;
extern const float lbl_122_rodata_58[];
extern float lbl_27_rodata_EF8;
void* fn_8009CD44(void*);
void fn_800A280C(void*, float);
double fn_80400AB8(double);
}

extern "C" void fn_122_14650(soModuleAccesser* accesser, float farg0) {
    const float* tbl = lbl_122_rodata_58;
    void* ai = g_cmAIController;
    void* cam = fn_8009CD44(CameraController::getInstance());
    if (ai != 0 || cam != 0) {
        farg0 *= soValueAccesser::getConstantFloat(accesser, 0xfb1, 0);
        float a = (float)fn_80400AB8(tbl[0] * lbl_27_rodata_EF8);
        float b = (float)fn_80400AB8(*(float*)((char*)cam + 0xd0));
        float ratio;
        if (b <= tbl[2]) {
            ratio = tbl[1];
        } else {
            ratio = a / b;
        }
        farg0 *= ratio;
        fn_800A280C(ai, farg0);
    }
}
