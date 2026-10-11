#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
extern const float lbl_99_rodata_10;
Vec2f* fn_99_AA80(Vec2f*, const Vec2f*);
}

extern "C" void fn_99_C850(soKineticEnergy* energy, soModuleAccesser* accesser) {
    switch (accesser->getKineticModule().getKineticType()) {
    case 0x66:
        if (accesser->getWorkManageModule().isFlag(0x22000014) == true) {
            Vec2f limit(soValueAccesser::getConstantFloat(accesser, 0xfb7, 0), lbl_99_rodata_10);
            fn_99_AA80(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x20), &limit);
        }
        break;
    default:
        break;
    }
    energy->updateEnergy(accesser);
}
