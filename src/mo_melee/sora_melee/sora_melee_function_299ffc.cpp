#include <so/so_module_accesser.h>
#pragma force_active on

extern const float lbl_27_rodata_46DC;
extern const float lbl_27_rodata_46C8;

struct CallbackContext {
    char padding[0x60];
    soModuleAccesser* accesser;
};

extern "C" int fn_27_299FFC(void*, CallbackContext* context) {
    soWorkManageModule& work = context->accesser->getWorkManageModule();
    int count = work.getInt(0x10000000);
    if (count > 0) {
        --count;
        if (count <= 0) {
            context->accesser->getMotionModule().addOtherAnim(
                lbl_27_rodata_46DC, lbl_27_rodata_46C8, 0, 8, false);
            context->accesser->getMotionModule().setOtherAnimRate(
                lbl_27_rodata_46DC, 0);
            context->accesser->getMotionModule().setOtherAnimFrame(
                lbl_27_rodata_46C8, 0);
        }
        work.setInt(count, 0x10000000);
    }
    return count;
}
