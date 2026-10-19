#include <stddef.h>
#pragma force_active on

typedef signed short s16;
typedef signed int s32;

extern "C" {

void fn_27_1988E4(void*, s16);
void __dl__FPv(void*);

void* fn_116_6DB0(void* p0, s32 p1) {
    if (p0 != NULL) {
        fn_27_1988E4(p0, -1);
        if ((s16)p1 > 0) {
            __dl__FPv(p0);
        }
    }
    return p0;
}

}
