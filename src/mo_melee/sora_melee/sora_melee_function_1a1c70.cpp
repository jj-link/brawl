#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u8 pad[8];
    u32 field8;
} FnObj;

extern "C" s32 fn_27_1A1C70(FnObj* p) {
    u32 w = p->field8;
    w = (w << 6) & 0xF0000000;
    return (s32)w >> 29;
}
