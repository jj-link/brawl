#include <types.h>
#pragma force_active on

struct PeachFloatHolder {
    u8 pad[0x14];
    float* values;
};

extern "C" void fn_103_A1CC(PeachFloatHolder* holder, s32 index, float value) {
    holder->values[index] -= value;
}
