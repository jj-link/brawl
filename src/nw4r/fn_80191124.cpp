#include <types.h>
#pragma force_active on

extern "C" u8 fn_80191124(u8** p) {
    u8* q = *p;
    if (q != 0) {
        return *q;
    }
    return 0;
}
