#pragma force_active on
extern "C" {
extern char lbl_27_data_3E650[];
}

struct fnObj27 {
    char* p0;
    char* p4;
    unsigned int p8;
};

extern "C" void fn_27_1A4038(fnObj27* self) {
    unsigned int v = self->p8;
    char* base = lbl_27_data_3E650;
    self->p0 = base;
    self->p4 = base + 0x48;
    self->p8 = v & 0x3FFFFF;
}
