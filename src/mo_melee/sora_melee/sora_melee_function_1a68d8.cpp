#pragma force_active on
extern char lbl_27_data_33D38[0x90];

struct FnObj {
    void* p0;
    void* p4;
    unsigned int p8;
};

extern "C" void fn_27_1A68D8(FnObj* self) {
    char* base = lbl_27_data_33D38;
    self->p0 = base;
    self->p4 = base + 0x48;
    self->p8 = self->p8 & 1;
}
