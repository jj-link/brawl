#include <types.h>
#pragma force_active on

extern "C" void fn_41_51B5C(void*, short);
extern "C" void fn_41_51984(void*, short);

extern "C" void* fn_41_519F0(char* self, short flag) {
    if (self != nullptr) {
        fn_41_51B5C(self + 0x68, -1);
        fn_41_51984(self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
