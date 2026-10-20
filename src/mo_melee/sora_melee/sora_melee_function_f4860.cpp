#pragma force_active on
typedef int s32;

struct Elem {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" {
Elem* fn_27_F4860(char* self, s32 idx)
{
    s32 r = (*(s32*)(self + 0x18) >> 28) + idx;
    if (r >= 4) {
        r -= 4;
    }
    return (Elem*)(self + 0x1c + r * 12);
}
}
