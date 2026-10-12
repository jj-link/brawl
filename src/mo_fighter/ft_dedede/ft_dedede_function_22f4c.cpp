#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>

extern "C" const float lbl_117_rodata_140;

extern "C" void fn_117_22F4C(void*, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    switch (accesser->getStatusModule().getStatusKind()) {
    case 19:
        accesser->getPostureModule().reverseLr();
        accesser->getWorkManageModule().setFloat(
            params->getParamFloat(accesser, 0xFB8, 0), 0x21000007);
        break;
    case 20:
        accesser->getWorkManageModule().offFlag(0x22000003);
        break;
    case 21:
        accesser->getWorkManageModule().setInt(
            params->getParamInt(accesser, 0x5DCD, 0), 0x20000005);
        break;
    case 22: {
        float chance = params->getParamFloat(accesser, 0xFBA, 0);
        if (randf() < chance) {
            Vec3f pos = accesser->getPostureModule().getPos();
            if (pos.m_x * accesser->getPostureModule().getLr() > lbl_117_rodata_140)
                accesser->getWorkManageModule().onFlag(0x22000008);
        }
        break;
    }
    case 23:
        if (!accesser->getWorkManageModule().isFlag(0x22000004)) {
            float amount = accesser->getWorkManageModule().getFloat(0x21000000);
            accesser->getWorkManageModule().addFloat(amount, 0x21000004);
            if (accesser->getWorkManageModule().getFloat(0x21000004) >=
                params->getParamFloat(accesser, 0xFAB, 0))
                accesser->getWorkManageModule().onFlag(0x22000004);
        }
        break;
    }
}
