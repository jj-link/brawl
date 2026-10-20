#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_1CF6DC(Obj* p) {
    return (s32)(((p->field >> 21) & 0x3F) << 26) >> 27;
}
