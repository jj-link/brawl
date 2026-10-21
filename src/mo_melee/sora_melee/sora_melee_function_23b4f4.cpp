#pragma force_active on
extern "C" {
extern const char lbl_27_data_4D1D8[];
extern const char lbl_27_data_4D260[];
void fn_27_23AAC4(void*, const char*);
}

struct Obj {
    char pad0[0x3C];
    const char* field3c;
    char pad40[8];
    void* field48;
    int field4c;
    int field50;
    unsigned char field54;
    unsigned char field55;
    unsigned char field56;
    unsigned char field57;
    unsigned char field58;
    char pad59[4];
    unsigned char flag7 : 1;
    unsigned char flag6 : 1;
    unsigned char padFlags : 2;
    unsigned char flags32 : 2;
    unsigned char lowFlags : 2;
};

extern "C" Obj* fn_27_23B4F4(Obj* self, void* arg) {
    fn_27_23AAC4(self, lbl_27_data_4D1D8);
    self->field3c = lbl_27_data_4D260;
    self->field48 = arg;
    self->field4c = -1;
    self->field50 = -1;
    self->field55 = 0;
    self->field56 = 0;
    self->field57 = 1;
    self->field58 = 0;
    self->flag7 = 0;
    self->flag6 = 1;
    self->flags32 = 0;
    return self;
}
