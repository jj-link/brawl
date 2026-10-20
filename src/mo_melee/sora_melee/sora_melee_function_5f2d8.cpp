#pragma force_active on
typedef unsigned char u8;

extern "C" const float lbl_27_rodata_828;
extern "C" void fn_27_B15B0(void*);

extern "C" void fn_27_5F2D8(void* self) {
    u8* p = reinterpret_cast<u8*>(self);
    float zero = lbl_27_rodata_828;
    *reinterpret_cast<u8*>(p + 0xa8) = 0;
    *reinterpret_cast<float*>(p + 0x94) = zero;
    *reinterpret_cast<float*>(p + 0x98) = zero;
    *reinterpret_cast<float*>(p + 0x9c) = zero;
    fn_27_B15B0(p + 0x44);
}
