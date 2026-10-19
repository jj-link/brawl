#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_C9EDC(void*, short);

extern "C" void* fn_96_34A0(void* self, short flag) {
    if (self != NULL) {
        fn_27_C9EDC(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
