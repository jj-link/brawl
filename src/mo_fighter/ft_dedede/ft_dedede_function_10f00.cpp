#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const float lbl_117_rodata_88;
extern const float lbl_117_rodata_8C;
float fn_117_10770(float);
}

// Interpolate the launch angle from the vertical stick and normalize negatives.
extern "C" void fn_117_10F00(void*, soModuleAccesser* accesser) {
    float angle = soValueAccesser::getConstantFloat(accesser, 0xFAC, 0);
    float stick = accesser->getControllerModule().getStickY();
    if (stick < lbl_117_rodata_88) {
        float difference;
        if (soValueAccesser::getConstantFloat(accesser, 0xFAD, 0) < lbl_117_rodata_88)
            difference = angle + fn_117_10770(soValueAccesser::getConstantFloat(accesser, 0xFAD, 0));
        else
            difference = angle - soValueAccesser::getConstantFloat(accesser, 0xFAD, 0);
        angle -= difference * fn_117_10770(stick);
    } else if (stick > lbl_117_rodata_88) {
        float difference = soValueAccesser::getConstantFloat(accesser, 0xFAE, 0) - angle;
        angle += difference * fn_117_10770(stick);
    }
    if (angle < lbl_117_rodata_88)
        angle += lbl_117_rodata_8C;
    accesser->getWorkManageModule().setFloat(angle, 0x21000004);
}
