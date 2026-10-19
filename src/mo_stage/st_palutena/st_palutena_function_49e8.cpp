#pragma force_active on
extern "C" {
extern char lbl_67_data_1A90[];
void fn_67_4AEC(void*);
void fn_67_4AFC(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* fn_67_49E8(void* p);
}

extern "C" void* fn_67_49E8(void* p) {
    unsigned char* self = (unsigned char*)p;
    *(char**)(self + 0x28) = lbl_67_data_1A90;
    *(char**)(self + 0x2C) = lbl_67_data_1A90 + 0x48;
    *(unsigned int*)(self + 0x30) &= 0x7FFFF;
    __construct_array(self + 0x34, fn_67_4AEC, fn_67_4AFC, 8, 6);
    return p;
}
