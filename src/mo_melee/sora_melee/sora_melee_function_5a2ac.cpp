#pragma force_active on
extern "C" const float lbl_27_rodata_7A0;

extern "C" void fn_27_5A2AC(void* self) {
    float v = lbl_27_rodata_7A0;
    *(float*)((char*)self + 0x14) = v;
    *(float*)((char*)self + 0x0C) = v;
}
