#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 fn_800DAA30(u32, u32, u32, u32);

struct Inner {
    u32 pad;
    u32 v;
};

struct Self {
    u8 pad0[0x70];
    u32 unk70;
    Inner* unk74;
    u8 pad1[0x1e0 - 0x78];
    u32 unk1e0;
    u32 unk1e4;
    u32 unk1e8;
};

extern "C" {
void fn_2_38E74(Self* r3) {
    Self* self = r3;
    self->unk1e4 = fn_800DAA30(self->unk1e0, self->unk70, self->unk74->v, self->unk1e8);
}
}
