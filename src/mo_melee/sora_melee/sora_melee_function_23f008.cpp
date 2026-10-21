#pragma force_active on

extern "C" {
extern const char lbl_27_data_4D438[];
extern const char lbl_27_data_4D51C[];
void fn_27_23AAC4(void*, const char*);
}

struct Obj {
    char pad0[0x3C];
    const char* field3c;
    char pad40[0x48];
    unsigned int field88;
    int field8c;
    int field90;
    unsigned int field94;
    unsigned char field98;
    unsigned char field99;
    char pad9a[2];
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    char padbc[4];
    unsigned int fieldc0;
    unsigned int fieldc4;
    unsigned int fieldc8;
};

extern "C" Obj* fn_27_23F008(Obj* self) {
    fn_27_23AAC4(self, lbl_27_data_4D438);
    self->field3c = lbl_27_data_4D51C;
    self->field88 = 0;
    self->field8c = -1;
    self->field90 = -1;
    self->field94 = 0;
    self->field98 = 0;
    self->field99 = 0;
    self->field9c = 0;
    self->fielda0 = 0;
    self->fielda4 = 0;
    self->fielda8 = 0;
    self->fieldac = 0;
    self->fieldb0 = 0;
    self->fieldb4 = 0;
    self->fieldb8 = 0;
    self->fieldc0 = 0;
    self->fieldc4 = 0;
    self->fieldc8 = 0;
    return self;
}