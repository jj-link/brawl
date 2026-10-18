#pragma force_active on
extern "C" {
extern char lbl_120_data_2D64[];

void fn_120_5BD8(void *p, unsigned char v)
{
    *(void **)p = lbl_120_data_2D64;
    ((unsigned char *)p)[4] = v;
}
}
