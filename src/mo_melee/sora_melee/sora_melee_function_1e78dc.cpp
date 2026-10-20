#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct FnObj {
    u8 pad[0x18];
    s32 flags;
};

extern "C" void* fn_27_1E78DC(FnObj* p, s32 idx) {
    s32 n = (p->flags >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (u8*)p + n * 12 + 0x1c;
}
