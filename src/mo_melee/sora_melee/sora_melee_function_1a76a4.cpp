#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" s32 fn_27_1A76A4(Obj *p) {
    u32 x = (u32)p->unk8;
    u32 r = (x << 8) | (x >> 24);
    return (s32)(r & 0xF8000000) >> 28;
}
