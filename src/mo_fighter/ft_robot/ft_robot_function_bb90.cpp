#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_120_9940(void*, short);
void __dl__FPv(void*);

void* fn_120_BB90(void* self, short flags) {
    if (self != NULL) {
        fn_120_9940(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
