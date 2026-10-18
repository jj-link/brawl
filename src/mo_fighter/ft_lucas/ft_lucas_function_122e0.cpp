#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* ptr);

void* fn_114_122E0(void* object, s16 flags) {
    if (object != 0 && flags > 0) {
        __dl__FPv(object);
    }
    return object;
}
}
