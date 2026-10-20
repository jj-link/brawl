#include <types.h>
#pragma force_active on

extern "C" void __dt__8clTargetFv(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" char* fn_27_46700(char* object, int flags) {
    if (object) {
        if (object + 0x20) {
            __destroy_arr(object + 0x2c, __dt__8clTargetFv, 8, 6);
        }
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
