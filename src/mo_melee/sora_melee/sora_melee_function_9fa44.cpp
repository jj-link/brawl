#include <types.h>
#pragma force_active on

namespace {
    struct Struct2C {
        u8 pad[0x28];
        bool flag;
    };
}

extern "C" void fn_27_9FA44(Struct2C* obj) {
    obj->flag = false;
}
