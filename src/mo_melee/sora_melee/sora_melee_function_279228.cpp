#pragma force_active on
extern "C" const float lbl_27_rodata_4520;
extern "C" const float lbl_27_rodata_4524;

extern "C" void fn_27_279228(void* self, unsigned int mode) {
    if (mode == 1) {
        *(float*)((char*)self + 0x64) = lbl_27_rodata_4520;
    } else {
        *(float*)((char*)self + 0x64) = lbl_27_rodata_4524;
    }
}
