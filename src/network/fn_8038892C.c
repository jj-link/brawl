#include <types.h>
#pragma force_active on

extern char *SOInetNtoA(u32 *);

char *fn_8038892C(u32 *arg0) {
    u32 sp8 = *arg0;
    return SOInetNtoA(&sp8);
}
