#pragma force_active on
extern "C" const float lbl_27_rodata_7A0;

extern "C" {
void fn_27_5A320(void *self)
{
    *(float *)((char *)self + 0x2C) = lbl_27_rodata_7A0;
    *(float *)((char *)self + 0x24) = lbl_27_rodata_7A0;
}
}
