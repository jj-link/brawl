#include <types.h>
#pragma force_active on

extern "C" void* fn_41_4E5B8(void* p, s16 del);
extern "C" void* fn_41_33D4C(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_4E614(void* p, s16 del) {
    if (p != nullptr) {
        fn_41_4E5B8((char*)p + 8, -1);
        fn_41_33D4C(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
