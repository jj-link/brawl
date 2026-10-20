#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Fn27Obj {
    u8 pad[8];
    s32 field8;
};

extern "C" {
void* fn_27_1B032C(Fn27Obj* self, s32 idx) {
    s32 v = self->field8 >> 29;
    s32 t = v + idx;
    if (t >= 2) {
        t -= 2;
    }
    return (char*)self + t * 0x60 + 0xc;
}
}
