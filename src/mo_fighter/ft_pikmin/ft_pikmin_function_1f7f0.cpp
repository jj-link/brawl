#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_98;
struct PikSlotA {};
struct PikSlotB {};
inline unsigned char* slotA(unsigned char* e, const PikSlotA&) { return e; }
inline float* slotB(unsigned char* e, const PikSlotB&) { return reinterpret_cast<float*>(e + 0x58); }

extern "C" void fn_113_1F7F0(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    unsigned char* e = slotA(energies, PikSlotA());
    e[0x15] |= 0x80;
    float scale = accesser->getPostureModule().getScale();
    float* v = slotB(energies, PikSlotB());
    float x = params->getParamFloat(accesser, 0xfb5, 0);
    if (scale < lbl_113_rodata_98) x *= scale;
    v[0] = x;
    float y = -params->getParamFloat(accesser, 0xfb6, 0);
    if (scale < lbl_113_rodata_98) y *= scale;
    v[1] = y;
    v[2] = -params->getParamFloat(accesser, 0xfb7, 0);
    energies[0x55] |= 0x80;
}
