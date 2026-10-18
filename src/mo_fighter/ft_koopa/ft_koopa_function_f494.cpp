#pragma force_active on
extern "C" unsigned char lbl_102_data_6208[];

extern "C" void *fn_102_F494(void *object)
{
    *(void **)object = (void *)&lbl_102_data_6208[0];
    return object;
}
