#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const float lbl_117_rodata_60, lbl_117_rodata_78;
float fn_117_10770(float value);
}

extern "C" void fn_117_10608(void*, soModuleAccesser* accesser) {
    float angle = soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
    float stick = accesser->getControllerModule().getStickY();
    float difference;
    if (stick < lbl_117_rodata_60) {
        if (soValueAccesser::getConstantFloat(accesser, 0xfad, 0) < lbl_117_rodata_60) {
            difference = angle + fn_117_10770(
                soValueAccesser::getConstantFloat(accesser, 0xfad, 0));
        } else {
            difference = angle - soValueAccesser::getConstantFloat(accesser, 0xfad, 0);
        }
        angle -= difference * fn_117_10770(stick);
    } else if (stick > lbl_117_rodata_60) {
        difference = soValueAccesser::getConstantFloat(accesser, 0xfae, 0) - angle;
        angle += difference * fn_117_10770(stick);
    }
    if (angle < lbl_117_rodata_60) {
        angle += lbl_117_rodata_78;
    }
    accesser->getWorkManageModule().setFloat(angle, 0x21000004);
}
