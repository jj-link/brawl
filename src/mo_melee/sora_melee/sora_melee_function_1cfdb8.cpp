#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct fn_27_Ring {
    u8 pad_0[8];
    s32 unk8;
};

extern "C" {
void* fn_27_1CFDB8(fn_27_Ring* p, s32 idx)
{
    s32 t = p->unk8 >> 27;
    s32 sum = t + idx;
    if (sum >= 8) {
        sum -= 8;
    }
    return (u8*)p + sum * 12 + 12;
}
}
