#pragma force_active on
extern "C" {

void fn_27_234C6C(void* self, void* value, unsigned char flag);

extern char lbl_40_data_1968[];
extern char lbl_40_data_19C8[];

struct Unk {
    unsigned int a;
    void* b;
    unsigned int c;
    unsigned char d;
    char pad[0x2F];
    void* e;
    void* f;
    void* g;
};

void* fn_40_DF98(Unk* self, void* arg1, unsigned char arg2) {
    fn_27_234C6C(self, arg1, arg2);
    self->f = arg1;
    self->b = &lbl_40_data_1968;
    self->e = &lbl_40_data_19C8;
    self->g = self;
    return self;
}

}
