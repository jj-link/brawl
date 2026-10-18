#pragma force_active on
extern "C" unsigned char lbl_93_data_8F68[];

extern "C" void fn_93_15344(void *object)
{
    *(void **)object = (void *)&lbl_93_data_8F68[0];
}
