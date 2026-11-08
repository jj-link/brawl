#include <types.h>
#pragma force_active on
extern "C" u8* fn_801D3698(u8, u32, void*);
extern "C" s32 fn_801C77E8(u8* __restrict arg0, u32 arg1, void* arg2) {
    u8* inner = *(u8**)(arg0 + 0x28);
    u8* result = fn_801D3698(inner[0x10], *(u32*)(inner + 0x14), inner);
    u8* r4;
    if (result == 0) r4 = 0;
    else if (arg1 >= *(u32*)result) r4 = 0;
    else {
        u8* entry = result + arg1 * 8;
        r4 = fn_801D3698(entry[4], *(u32*)(entry + 8), *(void**)(arg0 + 0x28));
    }
    if (r4 == 0) return 0;
    *(u32*)arg2 = r4[4];
    *(u32*)((u8*)arg2 + 4) = *(u32*)(r4 + 8);
    return 1;
}