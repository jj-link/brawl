#include <em/em_external_value_accesser.h>
#include <em/em_weapon_manager.h>
#pragma force_active on

extern "C" bool fn_41_6BC0(Enemy* em) {
    char* acc = *reinterpret_cast<char**>(reinterpret_cast<char*>(em) + 0x1b4);
    soWorkManageModule* wm = *reinterpret_cast<soWorkManageModule**>(acc + 0x64);
    return wm->isFlag(0x12000001);
}
