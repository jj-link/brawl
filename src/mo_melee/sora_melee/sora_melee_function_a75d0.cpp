#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Inner {
    u8 pad[0x1c];
    u8 f80 : 1;
    u8 rest : 7;
};

struct Outer {
    u32 unk0;
    Inner *inner;
    u32 unk8;
    u8 pad[0x1d - 0xc];
    u8 f80 : 1;
    u8 rest : 7;
};

extern "C" void fn_27_A75D0(Outer *self, u32 flag, u32 val) {
    if (flag != 0) {
        self->inner->f80 = 1;
    } else {
        self->inner->f80 = 0;
    }
    self->f80 = flag;
    self->unk8 = val;
}
