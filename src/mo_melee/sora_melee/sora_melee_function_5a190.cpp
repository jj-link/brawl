#pragma force_active on
extern "C" const float lbl_27_rodata_7A0;

extern "C" void fn_27_5A190(void *self)
{
    *(unsigned int *)((char *)self + 0x54) = 0;
    *(unsigned int *)((char *)self + 0x48) = 0;
    *(unsigned int *)((char *)self + 0x44) = 0;
    *(float *)((char *)self + 0x3C) = lbl_27_rodata_7A0;
    *(float *)((char *)self + 0x38) = lbl_27_rodata_7A0;
}
