#include <so/so_module_accesser.h>
#pragma force_active on

struct SnakeStatusReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_27_5A78(void*);

extern "C" void fn_122_26998(SnakeStatusReceiver* receiver) {
    if (receiver->accesser->getStatusModule().getStatusKind() == 0) {
        receiver->accesser->getWorkManageModule().offFlag(0x22000001);
    } else if (receiver->accesser->getStatusModule().getStatusKind() == 1) {
        receiver->accesser->getWorkManageModule().offFlag(0x22000000);
    }
    fn_27_5A78(receiver);
}
