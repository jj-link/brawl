#pragma force_active on
extern "C" {
extern char lbl_40_data_5840[];
void fn_40_1DF04(void*);
void fn_40_1DF14(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_40_1DE00(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x28) = lbl_40_data_5840;
    *(void**)(p + 0x2c) = lbl_40_data_5840 + 0x48;
    *(unsigned int*)(p + 0x30) &= 0x7ffff;
    __construct_array(p + 0x34, (void (*)(void*))fn_40_1DF04, (void (*)(void*))fn_40_1DF14, 8, 6);
    return self;
}
