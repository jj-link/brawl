#pragma force_active on
typedef int s32;
typedef unsigned char u8;

struct Fn27Obj {
    u8 pad0[8];
    s32 count;
};

extern "C" void* fn_27_1B07DC(Fn27Obj* self, s32 idx) {
    s32 i = (self->count >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return (u8*)self + 0xC + i * 0x24;
}
