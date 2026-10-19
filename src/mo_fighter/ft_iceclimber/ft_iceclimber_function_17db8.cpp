#pragma force_active on
extern "C" void fn_105_8058(void*, int);
extern "C" unsigned char lbl_105_data_8C4C[];

struct FtIceClimberObj {
    void* vtable;
    int unk4;
    void* param;
    int index;
};

extern "C" FtIceClimberObj* fn_105_17DB8(FtIceClimberObj* self, void* arg) {
    fn_105_8058(self, 0);
    self->vtable = lbl_105_data_8C4C;
    self->param = arg;
    self->index = -1;
    return self;
}
