#pragma force_active on
extern "C" char lbl_102_data_2054[];

extern "C" void fn_102_60D0(void *obj, unsigned char val)
{
    *(void **)obj = (void *)lbl_102_data_2054;
    ((unsigned char *)obj)[4] = val;
}
