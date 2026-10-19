#include <types.h>
#pragma force_active on

struct Fn125Triple {
    u32 c;
    u32 a;
    u32 b;
};

struct Fn125Aggregate;

extern "C" Fn125Triple fn_125_B4D8(Fn125Aggregate* arrays, s32 index);

extern "C" const Fn125Triple& fn_125_B604(Fn125Aggregate* arrays, s32 index) {
    return fn_125_B4D8(arrays, index);
}
