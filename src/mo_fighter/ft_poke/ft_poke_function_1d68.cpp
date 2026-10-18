#include <stddef.h>
#pragma force_active on

extern "C" {
void* fn_116_1D68(void* p, short flag) {
    if (p != NULL && flag > 0) {
        ::operator delete(p);
    }
    return p;
}
}
