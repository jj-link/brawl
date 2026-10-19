#pragma force_active on
extern "C" {
extern void fn_79_46B0(void*);
extern void fn_79_46C0(void*);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern unsigned char lbl_79_data_2498[];
}

extern "C" void* fn_79_44AC(void* self) {
    char* s = (char*)self;
    *(void**)(s + 0x28) = lbl_79_data_2498;
    *(void**)(s + 0x2C) = lbl_79_data_2498 + 0x48;
    *(unsigned int*)(s + 0x30) &= 0x7FFFF;
    __construct_array(s + 0x34, fn_79_46B0, fn_79_46C0, 8, 6);
    return self;
}
