#include <types.h>
#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_27_199E3C(void* ptr, short val) {
    if (ptr != 0 && val > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}
