#include <types.h>
#pragma force_active on

u32 fn_8035129C(u32 *arg0) {
    u32 x = (*arg0 >> 11) & 3;
    return (-x | x) >> 31;
}
