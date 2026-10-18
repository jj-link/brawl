#include <stddef.h>
#pragma force_active on

extern "C" {

void __dl__FPv(void*);

void* fn_97_1E14(void* self, short param) {
    if (self != 0 && param > 0) {
        __dl__FPv(self);
    }
    return self;
}

}
