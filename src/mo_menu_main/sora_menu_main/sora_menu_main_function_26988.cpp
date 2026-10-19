#include <types.h>
#pragma force_active on

struct Menu;

extern "C" u32 fn_18_12E0(Menu*);

extern "C" bool fn_2_26988(Menu* self) {
    return !(fn_18_12E0(self) & 0x20);
}
