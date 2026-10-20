#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct SoraAdvObj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_40_1E644(SoraAdvObj* obj) {
    u32 x = obj->field;
    return ((s32)((x << 4) & 0xF8000000u)) >> 28;
}
