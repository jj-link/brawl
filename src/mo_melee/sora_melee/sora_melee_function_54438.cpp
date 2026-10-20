#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Holder {
    u8 pad[8];
    s32 unk8;
};

extern "C" {
void *fn_27_54438(Holder *self, s32 idx) {
    s32 sh = self->unk8 >> 23;
    s32 n = sh + idx;
    if (n >= 0xff) {
        n -= 0xff;
    }
    return (u8 *)self + n * 8 + 0xc;
}
}
