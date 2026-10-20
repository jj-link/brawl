#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_540B0[0x28];

void fn_27_25CEA4(void *obj, unsigned char v)
{
    ((unsigned char *)obj)[4] = v;
    *(void **)obj = lbl_27_data_540B0;
}
}
