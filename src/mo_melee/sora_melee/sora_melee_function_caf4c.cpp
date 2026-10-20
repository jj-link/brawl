#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, unsigned long);
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
extern char lbl_27_data_1F410[];
}

extern "C" void* fn_27_CAF4C(char* self) {
    *(void**)(self + 0x0) = lbl_27_data_1F410;
    *(void**)(self + 0x4) = lbl_27_data_1F410 + 0x48;
    *(unsigned long*)(self + 0x8) &= 0xFFFF;
    __construct_array(self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 9);
    return self;
}
