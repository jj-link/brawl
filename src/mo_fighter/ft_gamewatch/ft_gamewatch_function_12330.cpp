#pragma force_active on
extern "C" {
extern const unsigned char lbl_107_data_8F88[0x40];
}

extern "C" void fn_107_12330(void *obj)
{
    *(const void **)obj = (const void *)lbl_107_data_8F88;
}
