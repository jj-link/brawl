#include <types.h>
#pragma force_active on

extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_6501C(void*, short);

extern "C" void* fn_41_65088(void* self, short shouldDelete) {
    if (self) {
        fn_41_65698(static_cast<char*>(self) + 0x128, -1);
        fn_41_6501C(static_cast<char*>(self) + 0x4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
