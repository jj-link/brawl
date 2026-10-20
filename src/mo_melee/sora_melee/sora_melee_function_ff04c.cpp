#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" void* fn_27_FF04C(Obj* self, s32 idx) {
    s32 n = (self->unk8 >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + n * 12 + 12;
}
