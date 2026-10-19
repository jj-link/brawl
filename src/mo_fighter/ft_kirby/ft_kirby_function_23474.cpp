#pragma force_active on
extern "C" void fn_96_1FD0(void*, int);
extern "C" unsigned char lbl_96_data_CCCC[];

struct FtKirbyObj {
    void* vtable;
    unsigned char pad[4];
    void* param;
    int index;
};

extern "C" void* fn_96_23474(FtKirbyObj* self, void* param) {
    fn_96_1FD0(self, 0);
    self->vtable = lbl_96_data_CCCC;
    self->param = param;
    self->index = -1;
    return self;
}
