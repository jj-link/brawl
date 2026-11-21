#include <so/so_value_accesser.h>
#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off
extern "C" void fn_27_15FBC8(int);
struct Energy { char padding[0x50]; float value; };
extern "C" void fn_27_331BFC(void*, Energy* energy, void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(18);
    bool flag[1] = {false};
    energy->value = soValueAccesser::getConstantFloat(accesser, 0xfb6, 0);
}
