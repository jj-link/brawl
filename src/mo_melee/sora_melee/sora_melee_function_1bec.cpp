#pragma force_active on
extern "C" void fn_27_70(void* self);
extern "C" unsigned char lbl_27_data_48[];

struct S {
    unsigned char pad[0x30];
    void* table;
};

extern "C" S* fn_27_1BEC(S* self) {
    fn_27_70(self);
    self->table = lbl_27_data_48;
    return self;
}
