#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad[2];
    u32 w;
};

extern "C" s32 fn_62_6134(Obj *p) {
    u32 x = p->w;
    return (s32)((x << 6) & 0xF0000000) >> 29;
}
