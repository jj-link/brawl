#include <so/so_module_accesser.h>
#include <so/damage/so_damage.h>

extern "C" const float lbl_117_rodata_150;

namespace {
// Overlay for the flag left unnamed in the shared soDamageLog layout.
struct DamageTransitionFlags {
    unsigned char : 2;
    bool requestStatusEight : 1;
    unsigned char : 5;
};
}

extern "C" bool fn_117_23B50(void*, int, soModuleAccesser* accesser,
                              const soDamageLog* damage) {
    accesser->getWorkManageModule().setFloat(damage->m_speed.m_x, 0x21000002);
    accesser->getWorkManageModule().setFloat(damage->m_speed.m_y, 0x21000003);
    accesser->getWorkManageModule().setFloat(damage->m_damageAdd, 0x21000000);
    accesser->getWorkManageModule().setFloat(damage->m_frame, 0x21000001);
    const DamageTransitionFlags* flags = reinterpret_cast<const DamageTransitionFlags*>(
        reinterpret_cast<const unsigned char*>(damage) + 0x45);
    if (flags->requestStatusEight) {
        return accesser->getStatusModule().changeStatusRequest(8, accesser);
    }
    if (damage->m_damageAdd > lbl_117_rodata_150) {
        if (accesser->getWorkManageModule().isFlag(0x22000005)) {
            return accesser->getStatusModule().changeStatusRequest(23, accesser);
        }
        return accesser->getStatusModule().changeStatusRequest(7, accesser);
    }
    return false;
}
