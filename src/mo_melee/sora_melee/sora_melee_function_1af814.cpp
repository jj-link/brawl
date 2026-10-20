#pragma force_active on
typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[1];
};

extern "C" void* fn_27_1AF814(Obj* self, s32 idx) {
    s32 n = (self->unk8 >> 22) + idx;
    if (n >= 0x125) {
        n -= 0x125;
    }
    return &self->unkC[n];
}
