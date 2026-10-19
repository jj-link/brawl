#pragma force_active on
extern "C" void fn_93_1AC4(void* self, int type);
extern "C" unsigned char lbl_93_data_8E74[];

struct FtLinkObj {
    void* vtable;
    int pad;
    void* param;
    int index;
};

extern "C" void* fn_93_12C58(FtLinkObj* self, void* param) {
    fn_93_1AC4(self, 0);
    self->vtable = lbl_93_data_8E74;
    self->param = param;
    self->index = -1;
    return self;
}
