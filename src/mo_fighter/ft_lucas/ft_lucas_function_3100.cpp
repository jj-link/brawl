#include <types.h>
#pragma force_active on

extern "C" void* fn_27_CB048(void*, short);
extern "C" void* fn_27_199214(void*, short);
extern "C" void* fn_27_A78FC(void*, short);
extern "C" void* fn_27_14E050(void*, short);
extern "C" void* fn_27_197EF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_3100(void* object, short deleting) {
    if (object != 0) {
        fn_27_CB048((char*)object + 0x220, -1);
        fn_27_199214((char*)object + 0x94, -1);
        fn_27_A78FC((char*)object + 0x78, -1);
        fn_27_14E050((char*)object + 0x10, -1);
        if (object != 0) {
            fn_27_197EF4(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
