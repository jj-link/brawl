#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct DiddyDamageReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" void fn_27_1DA968(void*, float, int, int);

extern "C" void fn_115_16C6C(DiddyDamageReceiver* receiver, float damage,
                              int kind, int flags) {
    if (receiver->accesser->getWorkManageModule().getFloat(0x11000001) < damage) {
        receiver->accesser->getWorkManageModule().setFloat(damage, 0x11000001);
    }
    fn_27_1DA968(receiver, damage, kind, flags);
}
