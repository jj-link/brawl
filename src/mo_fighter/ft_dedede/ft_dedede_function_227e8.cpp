#include <so/so_module_accesser.h>

// Read-only ABI view of the existing contiguous transition constants.
struct DededeTransitionConstants {
    float timerZero;
    float timerStep;
    double conversionBias;
    float facing;
    float nodeAngle;
};
extern "C" const float lbl_117_rodata_128;

extern "C" void fn_117_227E8(void*, soModuleAccesser* accesser) {
    const DededeTransitionConstants* constants =
        reinterpret_cast<const DededeTransitionConstants*>(&lbl_117_rodata_128);
    switch (accesser->getStatusModule().getStatusKind()) {
    case 5:
        if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(6), 0)) {
            accesser->getStatusModule().changeStatusRequest(6, accesser);
            accesser->getWorkManageModule().addInt(1, 0x20000002);
        }
        break;
    case 6:
        break;
    case 7:
        if (accesser->getWorkManageModule().getFloat(0x21000001) <= constants->timerZero)
            accesser->getStatusModule().changeStatusRequest(16, accesser);
        break;
    }
    if (accesser->getWorkManageModule().getInt(0x20000004) == 2 &&
        constants->facing == accesser->getPostureModule().getLr()) {
        accesser->getModelModule().setNodeRotateY(4, constants->nodeAngle);
    }
}
