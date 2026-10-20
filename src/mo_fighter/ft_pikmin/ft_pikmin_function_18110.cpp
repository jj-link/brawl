#include <so/so_module_accesser.h>
#pragma force_active on

struct PikminStatusReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" int fn_113_18110(PikminStatusReceiver* receiver) {
    switch (receiver->accesser->getStatusModule().getStatusKind()) {
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
        return 1;
    }
    return 0;
}
