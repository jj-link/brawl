#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_94_rodata_6C;
Vec3f* fn_94_94E0(Vec3f*, float, float, float);
}

extern "C" void fn_94_1A230(void*, soModuleAccesser* accesser, int status) {
    soLinkModule& link = accesser->getLinkModule();

    if (link.isLink(3) == 1) {
        if (link.isModelConstraint() == 1) {
            Vec3f a, b;
            link.adjustModelConstraintPosture(
                (Matrix*)fn_94_94E0(&a, lbl_94_rodata_6C, lbl_94_rodata_6C, lbl_94_rodata_6C),
                fn_94_94E0(&b, lbl_94_rodata_6C, lbl_94_rodata_6C, lbl_94_rodata_6C));
            link.removeModelConstraint(true);
        }
        link.unlink(3);
    }

    if (status == 0x115 || (unsigned)(status - 0x11b) <= 4) {
        return;
    } else {
        soWorkManageModule& work = accesser->getWorkManageModule();
        soPostureModule& posture = accesser->getPostureModule();
        if (work.isFlag(0x22000017)) {
            posture.reverseLr();
            posture.updateRotYLr();
        }
    }
}
