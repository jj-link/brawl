#pragma force_active on
extern "C" {
extern char lbl_27_data_1D4E8[];
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);

void* fn_27_CD8C8(void* self) {
    unsigned int* p = (unsigned int*)self;
    unsigned int base = (unsigned int)lbl_27_data_1D4E8;
    unsigned int value;
    p[0] = base;
    p[1] = base + 0x48;
    value = p[2] & 0x01FFFFFF;
    p[2] = value;
    __construct_array(p + 3, fn_27_AB128,
                      (void (*)(void*))fn_27_AB18C, 0x14, 1);
    return self;
}
}
