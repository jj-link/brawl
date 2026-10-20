#pragma force_active on
extern "C" {
extern float lbl_27_rodata_4450;
extern unsigned int lbl_27_data_57D18;

void fn_27_270FE0(char* p)
{
    float f = lbl_27_rodata_4450;
    *(unsigned char*)(p + 0x44) = 0;
    *(float*)(p + 0x40) = f;
    *(unsigned int*)(p + 0x4) = lbl_27_data_57D18;
}
}
