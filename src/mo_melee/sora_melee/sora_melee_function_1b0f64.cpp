#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad0[8];
    s32 unk8;
};

extern "C" void* fn_27_1B0F64(Obj* self, s32 idx) {
    s32 n = (self->unk8 >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (u8*)self + (n << 4) + 12;
}
