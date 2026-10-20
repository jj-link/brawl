#pragma force_active on
extern const float lbl_27_rodata_DB0;
extern const float lbl_27_rodata_DB4;
extern char lbl_27_data_16D08[];

struct Flags {
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char rest : 5;
};

struct Obj {
    Flags flags0;
    char pad1[3];
    int m4, m8, mC, m10;
    char pad14[0x14];
    float m28, m2C, m30, m34;
    int m38;
    Flags flags3C;
    char pad3D[3];
    void* m40;
};

extern "C" Obj* fn_27_B15E8(Obj* self) {
    self->flags0.b7 = 1;
    self->m40 = lbl_27_data_16D08;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m28 = lbl_27_rodata_DB0;
    self->m2C = lbl_27_rodata_DB0;
    self->m30 = lbl_27_rodata_DB0;
    self->m34 = lbl_27_rodata_DB4;
    self->flags3C.b7 = 1;
    self->flags3C.b6 = 0;
    self->flags3C.b5 = 1;
    return self;
}
