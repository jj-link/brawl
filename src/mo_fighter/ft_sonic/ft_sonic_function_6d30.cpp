#pragma force_active on
extern "C" {
extern char lbl_123_data_22F4[];

void fn_123_6D30(void *obj, unsigned char val)
{
    *(char **)obj = lbl_123_data_22F4;
    ((unsigned char *)obj)[4] = val;
}
}
