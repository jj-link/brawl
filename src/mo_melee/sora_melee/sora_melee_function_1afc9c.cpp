#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" void* fn_27_1AFC9C(Obj* p, s32 idx)
{
    s32 n = p->c >> 22;
    s32 sum = n + idx;
    if (sum >= 0x135) {
        sum -= 0x135;
    }
    return (u8*)p + sum * 4 + 0xC;
}
