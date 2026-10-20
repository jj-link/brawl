#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_19841C(void* self, short flag);
void operator delete(void* p);

extern "C" void* fn_113_29430(void* self, short flag) {
    if (self != NULL) {
        fn_27_19841C(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
