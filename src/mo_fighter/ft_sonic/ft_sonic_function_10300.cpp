#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_123_rodata_50;
extern const float lbl_123_rodata_54;
}

extern "C" void fn_123_10300(soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    float divisor = soValueAccesser::getConstantFloat(accesser, 0xfd8, 0);
    float ratio = work.getFloat(0x21000004) / divisor;
    if (ratio < lbl_123_rodata_50) {
        ratio = lbl_123_rodata_50;
    } else if (ratio > lbl_123_rodata_54) {
        ratio = lbl_123_rodata_54;
    }
    float rate = soValueAccesser::getConstantFloat(accesser, 0xfdb, 0) +
        ratio * (soValueAccesser::getConstantFloat(accesser, 0xfda, 0) -
                 soValueAccesser::getConstantFloat(accesser, 0xfdb, 0));
    accesser->getMotionModule().setRate(rate);
}
