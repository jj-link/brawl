#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1CFF7C(fn27Obj* p) {
    u32 t = p->unk8;
    t = t << 4;
    t = t & 0xF8000000;
    return (s32)t >> 28;
}
