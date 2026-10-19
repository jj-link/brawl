#pragma force_active on
extern "C" unsigned char lbl_123_data_65DC[];

extern "C" void fn_123_FD24(void **object)
{
    object[0] = (void *)lbl_123_data_65DC;
}
