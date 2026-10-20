#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_1A5260(Obj* o) {
    return ((s32)((o->flags >> 22) & 0xF) << 28) >> 29;
}
}
