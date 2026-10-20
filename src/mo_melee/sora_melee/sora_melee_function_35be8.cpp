#pragma force_active on
struct fn_27_35BE8_Obj {
    unsigned char pad[0x30];
    unsigned int unk30;
    unsigned int unk34;
};

extern "C" {
unsigned int fn_27_35BE8(fn_27_35BE8_Obj* p) {
    return p->unk34 != p->unk30;
}
}
