#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <math.h>
#pragma force_active on

struct SonicControlEnergy {
    float unk0;
    float unk4;
    float value8;
};

extern "C" {
extern const float lbl_123_rodata_9C;
}

extern "C" void fn_123_18500(SonicControlEnergy* energy, soModuleAccesser* accesser) {
    float stickY = accesser->getControllerModule().getStickY();
    double stickMag = fabs(stickY);
    float magnitude = (float)stickMag;
    if (magnitude < soValueAccesser::getConstantFloat(accesser, 0xfa4, 0)) {
        energy->value8 = soValueAccesser::getConstantFloat(accesser, 0xfa7, 0);
    } else {
        energy->value8 = lbl_123_rodata_9C;
    }
}
