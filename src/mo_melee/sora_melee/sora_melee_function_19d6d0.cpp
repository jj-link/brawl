#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" s32 fn_27_19D6D0(Obj* p) {
    u32 t = (p->flags >> 22) & 0xF;
    t <<= 28;
    return (s32)t >> 29;
}
