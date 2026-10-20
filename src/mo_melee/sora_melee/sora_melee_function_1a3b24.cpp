#pragma force_active on
struct fn27Obj {
    void* p0;
    void* p4;
    unsigned int p8;
};

extern char lbl_27_data_363B0[];

extern "C" {
void fn_27_1A3B24(fn27Obj* self) {
    char* base = lbl_27_data_363B0;
    unsigned int flag = self->p8;
    self->p0 = base;
    self->p4 = base + 0x48;
    self->p8 = flag & 1;
}
}
