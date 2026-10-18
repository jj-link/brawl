#pragma force_active on
extern "C" unsigned char lbl_95_data_7BA8[];

struct FighterObj {
    void* vtable;
    void* field4;
};

extern "C" void fn_95_F3C0(FighterObj* self, void* arg) {
    self->field4 = arg;
    self->vtable = lbl_95_data_7BA8;
}
