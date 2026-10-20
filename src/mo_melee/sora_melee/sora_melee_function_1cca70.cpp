#pragma force_active on
typedef int s32;

struct Obj
{
    s32 pad[6];
};

extern "C" void *fn_27_1CCA70(Obj *self, s32 index)
{
    s32 value = self->pad[6] >> 29;
    s32 result;

    if ((result = value + index) >= 2)
        result -= 2;

    return (char *)self + result * 12 + 28;
}
