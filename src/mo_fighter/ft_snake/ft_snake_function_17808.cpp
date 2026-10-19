#pragma force_active on
extern "C" void fn_122_AADC(void* self, unsigned char val);
extern "C" unsigned char lbl_122_data_E0A8[];

struct FtSnakeObj {
    void* vtable;
    void* unk4;
    void* param;
    int index;
};

extern "C" void* fn_122_17808(void* self, void* param) {
    FtSnakeObj* obj = (FtSnakeObj*)self;
    fn_122_AADC(self, 0);
    obj->vtable = lbl_122_data_E0A8;
    obj->param = param;
    obj->index = -1;
    return obj;
}
