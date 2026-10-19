#pragma force_active on
extern "C" {
void fn_40_2BB30(void* self);
}
extern const float lbl_40_rodata_468[];

extern "C" void fn_40_2C1AC(void* p) {
    char* self = (char*)p;
    *(unsigned char*)(self + 0x188) = 1;
    if (*(int*)(self + 0x170) != 2) {
        fn_40_2BB30(self);
    }
    *(float*)(self + 0x17c) = lbl_40_rodata_468[0];
}
