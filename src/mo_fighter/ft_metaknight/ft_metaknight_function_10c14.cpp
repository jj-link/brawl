#include <types.h>
#pragma force_active on

extern "C" bool fn_111_10C14(void*, int event) {
    s8 type = static_cast<s8>(event);
    int observed = 12;
    return static_cast<s8>(observed) == type;
}
