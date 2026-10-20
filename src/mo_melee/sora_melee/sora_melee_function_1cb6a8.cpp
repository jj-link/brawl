#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x18];
    s32 flags;
};

extern "C" {
void* fn_27_1CB6A8(Obj* self, u32 idx)
{
    s32 t = self->flags >> 28;
    s32 n = t + (s32)idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + n * 12 + 0x1c;
}
}
