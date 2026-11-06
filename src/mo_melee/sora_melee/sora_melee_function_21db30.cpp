#include <types.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

extern "C" void fn_27_21CECC(void*);
extern "C" const float lbl_27_rodata_3290[];

// Remaining mismatch: two relocations reference the compiler-generated
// constant pool instead of lbl_27_rodata_3290.

struct State {
    s32 active;
    char pad4[4];
    s8 value;
    char pad9[7];
    float amount;
};

extern "C" void fn_27_21DB30(State* self, s8 value, u32 force, s32 update) {
    if (self->value != value || force == 1U) {
        s8 result = nw4r::ut::Min<s8>(
            100, nw4r::ut::Max<s8>(0, value));

        self->value = result;

        float amount = self->value - 20;
        amount *= 0.5f;
        if (amount < 0.0f) {
            amount = 0.0f;
        } else if (amount > 30.0f) {
            amount = 30.0f;
        }

        self->amount = amount;

        if (self->active != 0 && update != 0) {
            fn_27_21CECC(self);
        }
    }
}
