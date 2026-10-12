#include <so/so_module_accesser.h>

extern "C" {
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
extern const float lbl_117_rodata_100, lbl_117_rodata_104;
}

extern "C" void fn_117_1C4B4(void*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 1:
    case 7:
        if (!accesser->getWorkManageModule().isFlag(0x22000005)) {
            accesser->getPostureModule().getLr();
            {
                soEffectModule& effect = accesser->getEffectModule();
                Vec3f position, rotation;
                int handle = effect.reqFollow(static_cast<EfID>(0x210003), 20,
                    fn_117_92AC(&position, lbl_117_rodata_100, lbl_117_rodata_100, lbl_117_rodata_100),
                    fn_117_92AC(&rotation, lbl_117_rodata_100, lbl_117_rodata_100, lbl_117_rodata_100),
                    lbl_117_rodata_104, false, 0, 0, -1);
                accesser->getWorkManageModule().setInt(handle, 0x20000000);
            }
            {
                soEffectModule& effect = accesser->getEffectModule();
                Vec3f position, rotation;
                int handle = effect.reqFollow(static_cast<EfID>(0x21000C), 11,
                    fn_117_92AC(&position, lbl_117_rodata_100, lbl_117_rodata_100, lbl_117_rodata_100),
                    fn_117_92AC(&rotation, lbl_117_rodata_100, lbl_117_rodata_100, lbl_117_rodata_100),
                    lbl_117_rodata_104, false, 0, 0, -1);
                accesser->getWorkManageModule().setInt(handle, 0x20000002);
            }
            accesser->getWorkManageModule().onFlag(0x22000005);
        }
        break;
    case 9:
        break;
    }
}
