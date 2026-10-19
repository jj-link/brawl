#include <types.h>
#pragma force_active on

extern "C" {
void fn_107_34D8(void* object, s16 arg);
void fn_107_4C44(void* object, s16 arg);
void __dl__FPv(void* object);

void* fn_107_345C(void* object, s16 deleting) {
    if (object != 0) {
        fn_107_34D8(static_cast<char*>(object) + 0xCDE4, -1);
        if (object != 0) {
            fn_107_4C44(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
