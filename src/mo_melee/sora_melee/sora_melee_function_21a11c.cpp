#include <types.h>
#pragma force_active on

extern "C" void* fn_27_21A11C(void* p) {
    s8 kind = (s8)((u8*)p)[0xA];
    if (kind == 1) {
        goto load;
    }
    if (kind == 4) {
        goto load;
    }
    if (kind == 5) {
        goto load;
    }
    return (void*)-1;
load:
    return *(void**)((u8*)p + 4);
}
