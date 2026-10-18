#pragma force_active on
extern "C" unsigned char lbl_102_data_7960[0x40];

extern "C" void *fn_102_17434(void **object)
{
    object[0] = (void *)&lbl_102_data_7960[0];
    return object;
}
