#include <stddef.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" void* fn_104_4154(void* p, short flags) {
    if (p != NULL && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
