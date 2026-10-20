#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x18];
    s32 v;
};

extern "C" {
void* fn_27_1BD32C(Obj* self, s32 idx)
{
    s32 i = (self->v >> 26) + idx;
    if (i >= 0x18) {
        i -= 0x18;
    }
    return (u8*)self + 0x1c + i * 12;
}
}
