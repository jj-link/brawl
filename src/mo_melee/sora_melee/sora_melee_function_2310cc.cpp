#pragma force_active on
typedef unsigned char u8;

struct fn27Inner {
    u8 pad[0x14];
    float unk14;
};

struct fn27Outer {
    u8 pad[0x78];
    fn27Inner* unk78;
};

extern "C" {
extern const float lbl_27_rodata_3804;

float fn_27_2310CC(fn27Outer* self) {
    if (self->unk78 == 0) {
        return lbl_27_rodata_3804;
    }
    return self->unk78->unk14;
}
}
