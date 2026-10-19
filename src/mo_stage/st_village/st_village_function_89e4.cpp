#pragma force_active on
extern "C" {
extern unsigned char lbl_70_data_3BD8[];
void fn_70_8B50(void*);
void* fn_70_8B60(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_70_89E4(void* self) {
    unsigned int value = *(unsigned int*)((char*)self + 0x30);
    *(void**)((char*)self + 0x28) = lbl_70_data_3BD8;
    *(void**)((char*)self + 0x2C) = lbl_70_data_3BD8 + 0x48;
    *(unsigned int*)((char*)self + 0x30) = value & 0x7ffff;
    __construct_array((char*)self + 0x34, fn_70_8B50, (void (*)(void*))fn_70_8B60, 8, 6);
    return self;
}
