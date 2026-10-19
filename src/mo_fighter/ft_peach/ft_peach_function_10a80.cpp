#pragma force_active on
typedef unsigned int u32;

typedef struct {
    unsigned char pad[0x48];
    u32 field;
    u32 values[1];
} PeachState;

extern "C" void fn_103_10A80(PeachState* state)
{
    state->field = 0;
    for (int i = 0; i < 1; ++i) {
        state->values[i] = 0;
    }
}
