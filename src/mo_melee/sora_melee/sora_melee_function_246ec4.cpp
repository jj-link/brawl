#include <types.h>
#pragma force_active on

extern "C" {

extern void fn_27_246654(void* a, int b);

void* fn_27_246EC4(void* a, s32 b) {
    if (a) {
        fn_27_246654(a, 0);
        if (b > 0)
            delete a;
    }
    return a;
}

}
