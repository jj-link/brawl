#pragma force_active on
extern "C" void fn_27_C10BC(void* self);
extern "C" unsigned char lbl_27_data_179D8[16];

extern "C" void* fn_27_C1454(void* self) {
    fn_27_C10BC(self);
    *(void**)((char*)self + 0x38) = lbl_27_data_179D8;
    return self;
}
