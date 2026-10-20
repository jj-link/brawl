#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_D19C8(Obj* p) {
    return (s32)((p->field8 << 10) & 0xFC000000) >> 27;
}
