#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_3544C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_104_4658(void* obj, short flag) {
    if (obj != 0) {
        fn_27_3544C(obj, -1);
        if ((int)flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
