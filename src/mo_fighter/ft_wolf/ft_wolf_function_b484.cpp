#include <types.h>
#pragma force_active on

struct Fn125Triple {
    u32 c;
    u32 a;
    u32 b;
};

struct Fn125Aggregate {
    void* vtable;
    Fn125Triple cache;
};

extern "C" Fn125Triple fn_125_B4D8(Fn125Aggregate* arrays, s32 index);

extern "C" Fn125Triple* fn_125_B484(Fn125Aggregate* arrays, s32 index) {
    arrays->cache = fn_125_B4D8(arrays, index);
    return &arrays->cache;
}
