#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
s32 fn_27_1CFB2C(Obj* obj) {
    u32 x = obj->flags;
    return (s32)((x << 6) & 0xFE000000) >> 26;
}
}
