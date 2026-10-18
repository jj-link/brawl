#pragma force_active on
extern "C" unsigned char lbl_113_data_AB48[];

struct FtObj {
    void* vtable;
    unsigned char flag;
};

extern "C" void fn_113_23A64(FtObj* self) {
    self->flag = 0;
    self->vtable = lbl_113_data_AB48;
}
