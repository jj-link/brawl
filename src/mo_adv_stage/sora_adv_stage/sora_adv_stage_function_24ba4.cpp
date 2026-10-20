#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

struct Obj {
    u32 pad[2];
    u32 flags;
};

extern "C" {
s32 fn_40_24BA4(Obj* p) {
    s32 t = (s32)(((p->flags >> 25) & 7) << 29);
    return t >> 30;
}
}
