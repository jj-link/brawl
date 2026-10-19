#include <types.h>
#pragma force_active on

extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5EA70(void*, short);

extern "C" void* fn_41_5EADC(void* self, short shouldDelete) {
    if (self) {
        fn_41_5EE64(static_cast<char*>(self) + 0x128, -1);
        fn_41_5EA70(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
