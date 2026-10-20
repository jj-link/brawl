#pragma force_active on
extern "C" {
extern char lbl_27_data_3AD8[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" char* fn_27_CCAC0(char* self) {
    *(void**)(self + 0x1c) = lbl_27_data_3AD8;
    *(void**)(self + 0x20) = lbl_27_data_3AD8 + 0x48;
    *(unsigned int*)(self + 0x24) &= 0x7FFFF;
    __construct_array(self + 0x28, (void (*)(void*))__ct__8clTargetFv,
                      (void (*)(void*))__dt__8clTargetFv, 8, 6);
    return self;
}
