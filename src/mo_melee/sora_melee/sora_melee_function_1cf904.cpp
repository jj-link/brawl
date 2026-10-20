#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 unk8;
};

extern "C" {
s32 fn_27_1CF904(Obj *p) {
    u32 v = p->unk8;
    return ((s32)(((v >> 19) & 0x7F) << 25)) >> 26;
}
}
