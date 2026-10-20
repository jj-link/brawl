#pragma force_active on
typedef unsigned char u8;

typedef struct FnObj {
    u8 pad[0x18];
    int unk18;
} FnObj;

extern "C" void* fn_27_1BFAE4(FnObj* p, int idx)
{
    int n = (p->unk18 >> 26) + idx;
    if (n >= 0x12) {
        n -= 0x12;
    }
    return (u8*)p + n * 12 + 0x1c;
}
