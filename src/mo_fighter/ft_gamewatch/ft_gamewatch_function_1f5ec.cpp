#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct GameWatchReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" void fn_107_1F5EC(GameWatchReceiver* receiver, float value) {
    if (receiver->accesser->getWorkManageModule().getFloat(0x11000001) < value) {
        receiver->accesser->getWorkManageModule().setFloat(value, 0x11000001);
    }
}
