#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_41_1592C(void* p);
extern float lbl_41_rodata_C3C;

extern "C" void fn_41_158E8(u8* self) {
    fn_41_1592C(self + 0x748);
    *(float*)(self + 0x764) = *(float*)(self + 0x764) + lbl_41_rodata_C3C;
}
