#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_1E7C98(FnObj* p) {
    u32 x = p->flags;
    s32 v = (s32)(((x >> 27) & 7) << 29);
    return v >> 30;
}
