#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_19C818(void*, short);

extern "C" void* fn_126_4B20(void* self, short flag) {
    if (self != NULL) {
        fn_27_19C818(self, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
