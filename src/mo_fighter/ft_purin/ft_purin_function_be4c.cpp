#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_124_rodata_1C;

extern "C" void fn_124_BE4C(void*, soModuleAccesser* accesser) {
    int kind = accesser->getStatusModule().getStatusKind();
    switch (kind) {
    case 0x116: {
        if (accesser->getWorkManageModule().isFlag(0x22000011)) {
            accesser->getWorkManageModule().addFloat(lbl_124_rodata_1C, 0x21000004);
            if (accesser->getWorkManageModule().isFlag(0x22000012)) {
                float diff = accesser->getMotionModule().getEndFrame(0x1EC) - accesser->getMotionModule().getFrame();
                float rate = diff / soValueAccesser::getConstantFloat(accesser, 0xFCE, 0);
                accesser->getMotionModule().setRate(rate);
                accesser->getWorkManageModule().setFloat(rate, 0x21000006);
                accesser->getWorkManageModule().offFlag(0x22000012);
            }
        }
        float t = accesser->getWorkManageModule().getFloat(0x21000004) /
                  soValueAccesser::getConstantFloat(accesser, 0xFCE, 0);
        float scale = lbl_124_rodata_1C +
                      t * (soValueAccesser::getConstantFloat(accesser, 0xFCD, 0) - lbl_124_rodata_1C);
        accesser->getPostureModule().setOwnerScale(scale);
        accesser->getWorkManageModule().setFloat(scale, 0x21000005);
        break;
    }
    case 0x11E: {
        accesser->getWorkManageModule().addFloat(lbl_124_rodata_1C, 0x21000004);
        float c = soValueAccesser::getConstantFloat(accesser, 0xFCD, 0);
        accesser->getPostureModule().setOwnerScale(c);
        break;
    }
    case 0x11F: {
        soWorkManageModule* work = &accesser->getWorkManageModule();
        float threshold = soValueAccesser::getConstantFloat(accesser, 0xFD0, 0);
        if (work->getFloat(0x21000004) < threshold) {
            accesser->getWorkManageModule().addFloat(lbl_124_rodata_1C, 0x21000004);
        }
        soWorkManageModule* work2 = &accesser->getWorkManageModule();
        float threshold2 = soValueAccesser::getConstantFloat(accesser, 0xFD0, 0);
        float t = work2->getFloat(0x21000004) / threshold2;
        float c = soValueAccesser::getConstantFloat(accesser, 0xFCD, 0);
        float scale = c + t * (lbl_124_rodata_1C - c);
        accesser->getPostureModule().setOwnerScale(scale);
        accesser->getWorkManageModule().setFloat(scale, 0x21000005);
        break;
    }
    }
}
