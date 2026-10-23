#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_C74E8(void*, short);
void* fn_106_5368(void*, short);
void* fn_106_1950(void*, short);
void __dl__FPv(void*);

void* fn_106_7D34(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short zero = 0;
        fn_27_C74E8(members + 0x8560, -1);
        fn_106_5368(members + 0x8554, zero);
        fn_106_1950(object, zero);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
