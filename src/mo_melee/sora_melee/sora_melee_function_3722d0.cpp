#pragma force_active on
typedef unsigned int u32;

struct Fn27Table {
    char pad0[0x14];
    int base;
};

extern "C" {
u32 fn_27_3722D0(Fn27Table* self, int unused, int a, int idx)
{
    int off = (a - self->base) * 4;
    u32* arr = *(u32**)((char*)self + off + 0x20);
    return arr[idx];
}
}
