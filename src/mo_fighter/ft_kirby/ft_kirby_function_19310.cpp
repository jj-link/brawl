#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_89DAC(int, soModuleAccesser*);
void fn_96_1A4F4(void*, soModuleAccesser*);
void fn_96_1A900(void*, soModuleAccesser*);
void fn_96_1AB54(void*, soModuleAccesser*);
}

extern "C" void fn_96_19310(void* process, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116:
        if (accesser->getGroundModule().isTouch((grCollStatus::TouchMask)2, 0)) {
            accesser->getWorkManageModule().offFlag(0x22000018);
            fn_27_89DAC(3, accesser);
        }
        break;
    case 0x12e:
        fn_96_1A4F4(process, accesser);
        break;
    case 0x130: {
        fn_96_1A900(process, accesser);
        Vec3f position = accesser->getLinkModule().getParentModelNodeGlobalPosition(6, (u32)0, false);
        accesser->getPostureModule().setPos(&position);
        break;
    }
    case 0x131:
        fn_96_1AB54(process, accesser);
        break;
    }
}
