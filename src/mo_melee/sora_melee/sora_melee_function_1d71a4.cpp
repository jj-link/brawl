#pragma force_active on
extern "C" {
extern char lbl_27_data_44CA0[];
void fn_27_1D57E0(void*);
void fn_27_8D588(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

void* fn_27_1D71A4(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x00) = lbl_27_data_44CA0;
    *(void**)(p + 0x04) = lbl_27_data_44CA0 + 0x48;
    *(unsigned int*)(p + 0x08) &= 0xFFFF;
    __construct_array(p + 0x0c, (void (*)(void*))fn_27_1D57E0, (void (*)(void*))fn_27_8D588, 12, 10);
    return self;
}
}
