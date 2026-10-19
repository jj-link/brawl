#include <types.h>
#pragma force_active on

extern "C" {
void fn_122_1A304(void* p, s16 v);
void __dl__FPv(void* p);

void* fn_122_1A2A8(void* p, s16 flags) {
    if (p != nullptr) {
        fn_122_1A304(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
