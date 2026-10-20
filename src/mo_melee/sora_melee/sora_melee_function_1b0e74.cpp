#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Fn27Obj {
    u8 pad[8];
    s32 field8;
};

extern "C" {
char* fn_27_1B0E74(Fn27Obj* self, s32 idx)
{
    s32 t = self->field8 >> 27;
    s32 n = t + idx;
    if (n >= 13) {
        n -= 13;
    }
    return (char*)self + n * 0x68 + 0xc;
}
}
