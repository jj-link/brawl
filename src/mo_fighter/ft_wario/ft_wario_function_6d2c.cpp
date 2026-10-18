#pragma force_active on
extern "C" {
extern char lbl_110_data_21E8[];

void fn_110_6D2C(void *obj, unsigned char flag)
{
    *(void **)obj = lbl_110_data_21E8;
    *((unsigned char *)obj + 4) = flag;
}
}
