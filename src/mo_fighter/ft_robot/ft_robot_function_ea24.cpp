#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" Vec3f* fn_120_8718(Vec3f*, float, float, float);
struct Constants { float zero, angle, one; };
extern "C" const Constants lbl_120_rodata_30;
extern "C" void fn_120_EA24(soModuleAccesser* a) {
    if (a->getWorkManageModule().isFlag(0x22000015)) {
        if (!a->getWorkManageModule().isFlag(0x22000014)) {
            soEffectModule& effect = a->getEffectModule();
            Vec3f pos, rot;
            int handle = effect.reqFollow((EfID)0x24000a, 0x60,
                fn_120_8718(&pos, 0.0f, 0.0f, 0.0f),
                fn_120_8718(&rot, 0.0f, 0.0f, -90.0f),
                1.0f, false, 1, 0, -1);
            a->getWorkManageModule().setInt(handle, 0x20000002);
            a->getWorkManageModule().onFlag(0x22000014);
        }
    } else if (a->getWorkManageModule().isFlag(0x22000014)) {
        soEffectModule& effect = a->getEffectModule();
        effect.kill(a->getWorkManageModule().getInt(0x20000002), true, true);
        a->getWorkManageModule().offFlag(0x22000014);
    }
    if (a->getWorkManageModule().getFloat(0x11000015) <= 0.0f) {
        if (a->getWorkManageModule().isFlag(0x22000013)) {
            int id = a->getWorkManageModule().getInt(0x20000001);
            a->getEffectModule().kill(id, true, true);
        }
        if (a->getWorkManageModule().isFlag(0x22000014)) {
            int id = a->getWorkManageModule().getInt(0x20000002);
            a->getEffectModule().kill(id, true, true);
        }
    }
}