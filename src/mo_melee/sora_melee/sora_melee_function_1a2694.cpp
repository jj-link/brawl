#include <types.h>
#pragma force_active on

struct S {
    char pad[8];
    int val;
};

extern "C" s32 fn_27_1A2694(S* self) {
    return self->val >> 28;
}
