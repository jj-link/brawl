#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_1D57E0(void*);
void fn_27_8D588(void*, int);
extern char lbl_27_data_44A90[];
}

extern "C" void* fn_27_1D548C(void* p) {
    char* self = (char*)p;
    *(void**)(self + 0x0) = (void*)(lbl_27_data_44A90 + 0x0);
    *(void**)(self + 0x4) = (void*)(lbl_27_data_44A90 + 0x48);
    *(unsigned int*)(self + 0x8) = *(unsigned int*)(self + 0x8) & 0xFFFF;
    __construct_array(self + 0xC, (void (*)(void*))fn_27_1D57E0, (void (*)(void*))fn_27_8D588, 0xC, 9);
    self[0x78] = 1;
    return self;
}
