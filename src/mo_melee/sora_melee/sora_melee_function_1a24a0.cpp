#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct FnObj {
    u8 pad[8];
    u32 field;
};

extern "C" {
int fn_27_1A24A0(FnObj* p) {
    return ((s32)((p->field << 5) & 0xFC000000)) >> 27;
}
}
