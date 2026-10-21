#pragma force_active on
extern "C" void fn_801052A8(void);

struct fn_800DCE8C_Inner {
    unsigned char pad0[0x30];
    unsigned char flag30;
    unsigned char pad1[0xe8 - 0x31];
    void* field_e8;
};

struct fn_800DCE8C_Outer {
    unsigned char pad0[0x78];
    fn_800DCE8C_Inner* inner;
};

extern "C" {
void fn_800DCE8C(fn_800DCE8C_Outer* self, void* val) {
    fn_800DCE8C_Inner* inner = self->inner;
    inner->field_e8 = val;
    if (inner->flag30 != 0) {
        fn_801052A8();
    }
}
}
