#include <types.h>
#pragma force_active on

// Work-manage-module style container: the float work array lives at +0x14.
struct FloatWorkHolder {
    unsigned char pad[0x14];
    float* floats;
};

extern "C" void fn_117_A7A8(FloatWorkHolder* holder, int index, float value) {
    holder->floats[index] = value;
}
