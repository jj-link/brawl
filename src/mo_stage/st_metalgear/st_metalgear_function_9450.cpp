#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_71_9554(void*);
void* fn_71_9564(void*, int);
}

extern unsigned char lbl_71_data_2C38[];

extern "C" void* fn_71_9450(void* p) {
    char* base = (char*)p;
    *(void**)(base + 0x28) = (void*)lbl_71_data_2C38;
    *(void**)(base + 0x2c) = (void*)(lbl_71_data_2C38 + 0x48);
    *(unsigned int*)(base + 0x30) &= 0x7FFFF;
    __construct_array(base + 0x34, (void (*)(void*))fn_71_9554, (void (*)(void*))fn_71_9564, 8, 6);
    return p;
}
