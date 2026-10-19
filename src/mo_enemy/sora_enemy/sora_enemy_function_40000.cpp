#include <types.h>
#pragma force_active on

extern "C" void fn_41_3FFA0(void*, short);
extern "C" void fn_41_3FEA0(void*, short);

extern "C" void* fn_41_40000(void* self, short flag) {
    if (self) {
        fn_41_3FFA0(static_cast<char*>(self) + 0xF8, -1);
        fn_41_3FEA0(static_cast<char*>(self) + 0x4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
