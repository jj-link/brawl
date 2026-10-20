#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_2346EC(u8* self, u8 val) {
    if (self[0x2f] == 0) {
        self[0x2c] = val;
    }
}
}
