#pragma force_active on
extern "C" void* fn_27_14B5F8(void*);
extern "C" char lbl_118_data_6270[];

extern "C" void* fn_118_D5B0(void* self) {
    fn_27_14B5F8(self);
    *static_cast<void**>(self) = lbl_118_data_6270;
    return self;
}
