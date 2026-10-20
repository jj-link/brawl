#pragma force_active on
typedef int s32;

struct Fn27Table {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" {
void* fn_27_1AFDB4(Fn27Table* self, s32 idx) {
    s32 n = (self->unk8 >> 22) + idx;
    if (n >= 0x123) {
        n -= 0x123;
    }
    return (char*)self + (n << 2) + 0xc;
}
}
