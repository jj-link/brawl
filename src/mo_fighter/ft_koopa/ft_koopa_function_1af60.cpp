#include <cstddef>
#pragma force_active on

extern "C" void* fn_102_3E54(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_1AF60(void* obj, short n) {
    if (obj != NULL) {
        fn_102_3E54(obj, 0);
        if (n > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
