#pragma force_active on
extern "C" void fn_94_6C20(void* obj, unsigned char val);
extern "C" unsigned char lbl_94_data_CF2C[];

namespace {
struct FtSamusObjStorage {
    void* vtable;
    int pad;
    void* param;
    int index;
};
}

extern "C" void* fn_94_1CD74(FtSamusObjStorage* self, void* param) {
    fn_94_6C20(self, 0);
    self->vtable = lbl_94_data_CF2C;
    self->param = param;
    self->index = -1;
    return self;
}
