#include <stddef.h>
#pragma force_active on

extern "C" {
void* fn_110_F0E4(void* p, short flag) {
    if (p != NULL) {
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
