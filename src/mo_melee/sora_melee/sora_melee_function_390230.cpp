#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_390230(Fn27Obj* obj) {
    u32 v = obj->flags;
    return (s32)(((v >> 25) & 0xF) << 28) >> 29;
}
