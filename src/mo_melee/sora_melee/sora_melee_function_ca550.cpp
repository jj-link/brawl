#pragma force_active on
extern "C" {
extern char lbl_27_data_1F9B0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_27_CA550(char* self) {
    unsigned int v = *(unsigned int*)(self + 0x8);
    *(char**)(self + 0x0) = lbl_27_data_1F9B0;
    *(char**)(self + 0x4) = lbl_27_data_1F9B0 + 0x48;
    *(unsigned int*)(self + 0x8) = v & 0xffff;
    __construct_array(self + 0xc, fn_27_A6948, fn_27_A6978, 0x24, 0xc);
    return self;
}
