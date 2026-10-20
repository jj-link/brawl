#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 word;
};

extern "C" s32 fn_27_CF228(Obj* p) {
    u32 w = p->word;
    u32 r = (w << 12) | (w >> 20);
    s32 s = (s32)(r & 0xFE000000);
    return s >> 26;
}
