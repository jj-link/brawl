#pragma force_active on
extern "C" void fn_27_23B4F4(void* self);
extern "C" unsigned char lbl_27_data_4D360[];

extern "C" void* fn_27_23EB70(void* self) {
    unsigned char* p = (unsigned char*)self;
    fn_27_23B4F4(self);
    unsigned int zero = 0;
    *(unsigned char**)(p + 0x3c) = lbl_27_data_4D360;
    *(unsigned int*)(p + 0x60) = zero;
    *(unsigned char*)(p + 0x64) = zero;
    *(unsigned int*)(p + 0x68) = 0x4f;
    return self;
}
