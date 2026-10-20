#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Owner {
    u8 pad0[8];
    s32 m8;
};

extern "C" void* fn_27_3958B4(Owner* self, s32 idx) {
    s32 n = self->m8 >> 28;
    s32 i = (n + idx);
    if (i >= 4) {
        i -= 4;
    }
    return (u8*)self + 0xC + i * 0x34;
}
