#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_14CD30(void*, short);
void operator delete(void* p);

extern "C" void* fn_104_2BD0(void* self, short flag) {
    if (self != NULL) {
        fn_27_14CD30(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
