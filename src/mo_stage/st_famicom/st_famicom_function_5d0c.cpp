#pragma force_active on
extern "C" void fn_68_5E10(void*);
extern "C" void fn_68_5E20(void*);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

extern "C" char lbl_68_data_1A68[];

extern "C" void* fn_68_5D0C(void* _this) {
    char* self = (char*)_this;
    *(void**)(self + 0x28) = lbl_68_data_1A68;
    *(void**)(self + 0x2C) = lbl_68_data_1A68 + 0x48;
    *(unsigned int*)(self + 0x30) &= 0x7FFFF;
    __construct_array(self + 0x34, fn_68_5E10, fn_68_5E20, 8, 6);
    return _this;
}
