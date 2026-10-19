#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);
void* fn_93_12A74(void* p, short n);

void* fn_93_12AB4(void* p, short n) {
    void* result;
    if (p != NULL) {
        short zero = 0;
        result = fn_93_12A74(p, zero);
        if (n > 0)
            __dl__FPv(p);
        result = p;
    }
    return result;
}
}