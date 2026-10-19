#include <types.h>
#pragma force_active on

extern "C" void fn_41_556F4(void*, short);
extern "C" void fn_41_5551C(void*, short);

extern "C" void* fn_41_55588(void* self, short flag) {
    if (self) {
        fn_41_556F4((char*)self + 0x68, -1);
        fn_41_5551C((char*)self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
