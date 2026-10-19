#pragma force_active on
extern "C" void fn_112_7674(void* obj, unsigned char b);
extern "C" unsigned char lbl_112_data_74C8[];

struct FtPitObj {
    void* vtable;
    int unk4;
    void* field8;
    int field0c;
};

extern "C" FtPitObj* fn_112_10B94(FtPitObj* self, void* param) {
    fn_112_7674(self, 0);
    self->vtable = lbl_112_data_74C8;
    self->field8 = param;
    self->field0c = -1;
    return self;
}
