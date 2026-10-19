#pragma force_active on
extern "C" {
extern char lbl_56_data_24D0[];
void fn_56_5A00(void* data);
void* fn_56_5A10(void* p, int flags);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_56_5770(void* self) {
    char* p = (char*)self;
    *(char**)(p + 0x28) = lbl_56_data_24D0;
    *(char**)(p + 0x2C) = lbl_56_data_24D0 + 0x48;
    *(unsigned long*)(p + 0x30) = *(unsigned long*)(p + 0x30) & 0x7FFFF;
    __construct_array(p + 0x34, fn_56_5A00, (void (*)(void*))fn_56_5A10, 8, 6);
    return self;
}
