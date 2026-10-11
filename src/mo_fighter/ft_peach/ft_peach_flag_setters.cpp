#include <types.h>

struct PeachFlagState {
    u8 unknown[0x31];
    u8 enabled;
};

extern "C" {
void fn_103_C220(PeachFlagState* state) {
    state->enabled = 0;
}

void fn_103_C22C(PeachFlagState* state) {
    state->enabled = 1;
}
}
