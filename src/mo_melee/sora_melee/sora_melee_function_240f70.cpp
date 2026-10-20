#pragma force_active on
struct Fn27Obj {
    unsigned char padding[0x3C];
    void* table;
};

extern "C" void fn_27_2407E0(Fn27Obj* self);
extern "C" unsigned char lbl_27_data_4DA20[];

extern "C" Fn27Obj* fn_27_240F70(Fn27Obj* self) {
    fn_27_2407E0(self);
    self->table = lbl_27_data_4DA20;
    return self;
}
