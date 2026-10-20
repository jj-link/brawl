#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct fn_27_Obj {
    u8 pad[8];
    u32 unk8;
};

extern "C" {
s32 fn_27_1A41BC(fn_27_Obj* p) {
    return (s32)((p->unk8 << 10) & 0xFFE00000) >> 22;
}
}
