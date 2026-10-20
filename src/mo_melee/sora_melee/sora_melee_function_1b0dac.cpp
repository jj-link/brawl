#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Sub {
    char data[0x1c];
};

struct Owner {
    u32 unk0;
    u32 unk4;
    s32 val;
    Sub arr[4];
};

extern "C" void* fn_27_1B0DAC(Owner* p, s32 idx)
{
    s32 i = (p->val >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return &p->arr[i];
}
