#include <types.h>
#pragma force_active on

extern "C" void* fn_41_4B920(void* p, s16 n);
extern "C" void* fn_41_33D4C(void* p, s16 n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B984(void* p, s16 n) {
    if (p != nullptr) {
        fn_41_4B920(reinterpret_cast<u8*>(p) + 0x8, -1);
        fn_41_33D4C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
