#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct SonicDamageReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" void fn_27_1DA968(void*, float, int, int);

extern "C" void fn_123_16EF0(SonicDamageReceiver* receiver, float damage,
                              int kind, int flags) {
    if (receiver->accesser->getWorkManageModule().getFloat(0x11000001) < damage) {
        receiver->accesser->getWorkManageModule().setFloat(damage, 0x11000001);
    }
    fn_27_1DA968(receiver, damage, kind, flags);
}