#include <so/so_module_accesser.h>
#include <so/damage/so_damage.h>
#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
extern "C" int fn_27_61334(soModuleAccesser*, int);

extern "C" void fn_115_111D4(
    void*, int argument, soModuleAccesser* accesser, const soDamageLog* damage) {
    accesser->getWorkManageModule().setFloat(damage->m_speed.m_x, 0x21000009);
    accesser->getWorkManageModule().setFloat(damage->m_speed.m_y, 0x2100000A);
    accesser->getWorkManageModule().setFloat(damage->m_frame, 0x2100000B);

    if (accesser->getStatusModule().getStatusKind() == 0x125) {
        accesser->getStatusModule().changeStatusRequest(0x126, accesser);
    } else if (accesser->getStatusModule().getStatusKind() == 0x127) {
        if (damage->m_reaction > getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xFB3, 0)) {
            accesser->getWorkManageModule().onFlag(0x22000013);
        }
        accesser->getStatusModule().changeStatusRequest(0x128, accesser);
    } else {
        int request = fn_27_61334(accesser, argument);
        accesser->getStatusModule().changeStatusRequest(request, accesser);
    }
}
