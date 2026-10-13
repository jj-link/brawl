#include <so/so_module_accesser.h>

namespace {
struct DededeStatusReceiver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" int fn_27_1DB358(void*);

extern "C" int fn_117_20C40(DededeStatusReceiver* receiver) {
    switch (receiver->accesser->getStatusModule().getStatusKind()) {
    case 8:
    case 9:
        return 0;
    }
    if (receiver->accesser->getWorkManageModule().isFlag(0x22000004)) {
        return 0;
    }
    return fn_27_1DB358(receiver);
}
