#pragma force_active on
extern "C" {
void fn_98_7374(void* object, unsigned char value);
extern char lbl_98_data_24EC[];
}

extern "C" void* fn_98_855C(char* self, int a4, int a5, int a6, int a7, int a8, int a9) {
    fn_98_7374(self, 0);
    char* base = lbl_98_data_24EC;
    *(char**)(self + 0x8) = base;
    *(char**)(self + 0x0) = base + 8;
    *(int*)(self + 0xc) = a4;
    *(int*)(self + 0x10) = a5;
    *(int*)(self + 0x14) = a6;
    *(int*)(self + 0x18) = a7;
    *(int*)(self + 0x1c) = a8;
    *(int*)(self + 0x20) = a9;
    return self;
}
