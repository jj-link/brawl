#pragma force_active on
extern "C" unsigned char lbl_95_data_7D30[];

struct FtYoshiObj {
    void* vtable;
    void* field;
};

extern "C" void fn_95_F784(FtYoshiObj* self, void* arg) {
    self->field = arg;
    self->vtable = lbl_95_data_7D30;
}
