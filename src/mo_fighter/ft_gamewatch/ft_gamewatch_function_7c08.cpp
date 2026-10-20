#include <st/module.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_48568(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CDDE8(void*, short);
extern "C" void* fn_27_CD78C(void*, short);

extern "C" void* fn_107_7C08(void* object, short deleting) {
    if (object != 0) {
        char* p = static_cast<char*>(object);
        fn_27_48BE8(p + 0x1C4, -1);
        fn_27_48568(p + 0x1B4, -1);
        fn_27_4CAA0(p + 0x130, -1);
        fn_27_CDDE8(p + 0x6C, -1);
        fn_27_CD78C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
