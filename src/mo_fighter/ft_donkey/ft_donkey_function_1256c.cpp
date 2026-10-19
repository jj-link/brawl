#pragma force_active on
extern "C" void fn_92_6DC4(void* self, int flag);
extern "C" unsigned char lbl_92_data_72A0[];

struct FtDonkeyObj {
    void* vtable;
    int pad4;
    void* param;
    int index;
};

extern "C" FtDonkeyObj* fn_92_1256C(FtDonkeyObj* self, void* param) {
    fn_92_6DC4(self, 0);
    self->vtable = lbl_92_data_72A0;
    self->param = param;
    self->index = -1;
    return self;
}
