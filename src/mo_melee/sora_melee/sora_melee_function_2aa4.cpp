#pragma force_active on
extern "C" void fn_27_70(void* self);
extern "C" char lbl_27_data_98[];

struct Fn27Obj {
    char pad[0x30];
    char* field30;
};

extern "C" Fn27Obj* fn_27_2AA4(Fn27Obj* self) {
    fn_27_70(self);
    self->field30 = lbl_27_data_98;
    return self;
}
