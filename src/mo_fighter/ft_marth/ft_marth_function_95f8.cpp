#include <types.h>
#pragma force_active on

struct MarthState {
    u8 pad[0x31];
    u8 field;
};

extern "C" void fn_106_95F8(MarthState* s) {
    s->field = 0;
}
