#pragma force_active on
typedef unsigned long u32;

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern char lbl_27_data_3A338[];
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);

char* fn_27_198D94(char* self) {
    *(void**)self = lbl_27_data_3A338;
    *(void**)(self + 4) = lbl_27_data_3A338 + 0x48;
    *(u32*)(self + 8) &= 0x01FFFFFF;
    __construct_array(self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 1);
    return self;
}
}
