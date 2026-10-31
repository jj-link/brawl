#include <so/so_module_accesser.h>

#pragma force_active on

struct PikminStatusReceiver19E30 {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" int fn_113_19E30(PikminStatusReceiver19E30* receiver) {
    switch (receiver->accesser->getStatusModule().getStatusKind()) {
    case 14:
    case 16:
    case 19:
    case 21:
    case 28:
    case 37:
    case 47:
        return 1;
    }
    return 0;
}
