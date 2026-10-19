#include <types.h>
#pragma force_active on

extern "C" void fn_41_379B0(void* self, s16 p);
extern "C" void fn_41_37B18(void* self, s16 p);

extern "C" void* fn_41_37A1C(void* self, s16 shouldDelete) {
    if (self != nullptr) {
        fn_41_37B18((char*)self + 0x98, -1);
        fn_41_379B0((char*)self + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
