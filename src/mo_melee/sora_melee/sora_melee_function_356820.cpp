#pragma force_active on
extern unsigned char lbl_27_data_8F260[0x50];

extern "C" {
void fn_27_356820(void **p)
{
    *p = lbl_27_data_8F260;
}
}
