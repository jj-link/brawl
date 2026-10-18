#include <stddef.h>
#pragma force_active on

extern "C" void* fn_122_9DCC(void* p, short n) {
    if (p != NULL) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
