#include <types.h>
#pragma force_active on

extern "C" void fn_41_4B854(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B920(void* p, short n) {
    if (p != nullptr) {
        if (p != nullptr) {
            fn_41_4B854(static_cast<char*>(p) + 4, -1);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
