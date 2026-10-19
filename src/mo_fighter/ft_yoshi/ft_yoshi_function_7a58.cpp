#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_19C818(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_7A58(void* self, short kind) {
    if (self) {
        fn_27_19C818(self, -1);
        if (kind > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
