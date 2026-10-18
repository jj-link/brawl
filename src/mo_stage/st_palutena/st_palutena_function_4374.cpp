#include <stddef.h>
#pragma force_active on

extern "C" void* fn_67_4374(void* p, int flag) {
    if (p != NULL && flag > 0) {
        ::operator delete(p);
    }
    return p;
}
