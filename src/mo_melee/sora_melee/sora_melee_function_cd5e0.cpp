#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3AD8[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" void* fn_27_CD5E0(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x20) = lbl_27_data_3AD8;
    *(void**)(p + 0x24) = lbl_27_data_3AD8 + 0x48;
    *(u32*)(p + 0x28) &= 0x7FFFF;
    __construct_array(p + 0x2c, (void (*)(void*))__ct__8clTargetFv, (void (*)(void*))__dt__8clTargetFv, 8, 6);
    return self;
}
