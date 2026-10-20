#pragma force_active on
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 pad[8];
    s32 f8;
} S;

extern "C" {
void* fn_27_D9408(S* self, s32 n)
{
    s32 i = (self->f8 >> 26) + n;
    if (i >= 0x1f) {
        i -= 0x1f;
    }
    return (u8*)self + i * 0x30 + 0xc;
}
}
