#include <types.h>
#pragma force_active on

extern "C" void fn_41_2FA00(void* p, short v);
extern "C" void fn_41_28D0(void* p, short v);

extern "C" void* fn_41_2FA70(void* p, short flag) {
    if (p) {
        short m = -1;
        fn_41_2FA00((char*)p + 0x24, m);
        fn_41_28D0(p, m);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
