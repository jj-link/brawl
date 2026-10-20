#pragma force_active on
struct fn_27_Obj {
    char pad[0x40];
    float unk40;
};

extern const float lbl_27_rodata_3B8;

extern "C" float fn_27_25524(fn_27_Obj* self) {
    return lbl_27_rodata_3B8 * self->unk40;
}
