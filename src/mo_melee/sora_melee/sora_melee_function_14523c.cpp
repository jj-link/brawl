#pragma force_active on
extern "C" void fn_27_6FE94(void*, int);
extern "C" unsigned char lbl_27_data_2BB78[];
extern "C" unsigned char lbl_27_data_2BAE8[];

extern "C" void* fn_27_14523C(void* self) {
    unsigned char* p = (unsigned char*)self;
    void* first = lbl_27_data_2BB78;
    void* second = lbl_27_data_2BAE8;
    *(void**)(p + 0x0C) = first;
    p[0x08] = 0;
    p[0x10] = 0;
    *(void**)(p + 0x14) = second;
    fn_27_6FE94(p + 0x1C, 0);
    *(unsigned int*)(p + 0x24) = 0xFF;
    *(unsigned int*)(p + 0x28) = 0;
    *(unsigned int*)(p + 0x2C) = 0xFFFFFFFF;
    return self;
}
