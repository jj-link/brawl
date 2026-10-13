#include <so/so_module_accesser.h>

namespace {
struct DededeDamageReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" void fn_27_1DA968(void*, float, int, int);

extern "C" void fn_117_20568(DededeDamageReceiver* receiver, float damage,
                              int kind, int flags) {
    if (receiver->accesser->getWorkManageModule().getFloat(0x11000001) < damage) {
        receiver->accesser->getWorkManageModule().setFloat(damage, 0x11000001);
    }
    fn_27_1DA968(receiver, damage, kind, flags);
}
