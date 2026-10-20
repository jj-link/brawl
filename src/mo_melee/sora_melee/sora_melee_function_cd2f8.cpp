#pragma force_active on
extern "C" {
extern char lbl_27_data_3AD8[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

void* fn_27_CD2F8(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x1c) = lbl_27_data_3AD8;
    *(void**)(p + 0x20) = lbl_27_data_3AD8 + 0x48;
    *(unsigned int*)(p + 0x24) &= 0x7FFFF;
    __construct_array(p + 0x28, (void (*)(void*))__ct__8clTargetFv, (void (*)(void*))__dt__8clTargetFv, 8, 6);
    return self;
}
}
