#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off
typedef unsigned int u32;
typedef int s32;

void fn_801E6AC4(s32 arg0, s32 arg1) {
    u32* p = (u32*)(arg0 * 0xC);
    u32 base = 0xCD000000;
    p = (u32*)(base + (u32)p);
    p[0x6400 / 4] = arg1;
}
