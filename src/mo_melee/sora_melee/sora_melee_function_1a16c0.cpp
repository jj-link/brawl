#pragma force_active on
extern "C" {
extern char lbl_27_data_371E0[];
void fn_27_D2A0C(void*);
void* fn_27_AB510(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_27_1A16C0(void* self) {
    unsigned int* p = (unsigned int*)self;
    unsigned int value = p[2];
    p[0] = (unsigned int)lbl_27_data_371E0;
    p[1] = (unsigned int)(lbl_27_data_371E0 + 0x48);
    p[2] = value & 0x1FFF;
    __construct_array((char*)self + 0x0C, fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, (unsigned long)0x10, 0x10);
    return self;
}
