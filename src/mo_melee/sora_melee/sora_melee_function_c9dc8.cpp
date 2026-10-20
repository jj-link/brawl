#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    u8 pad[8];
    u32 flags;
};

extern "C" s32 fn_27_C9DC8(FnObj* p) {
    return (s32)((p->flags << 2) & 0xE0000000) >> 30;
}
