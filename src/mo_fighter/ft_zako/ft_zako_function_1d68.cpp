#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_7700(void*, short);
void __dl__FPv(void*);

void* fn_126_1D68(void* ptr, short val) {
    if (ptr != NULL) {
        fn_27_7700(ptr, 0);
        if (val > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
