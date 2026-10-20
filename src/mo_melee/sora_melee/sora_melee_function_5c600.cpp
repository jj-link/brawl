#pragma force_active on
extern "C" void fn_27_5C600(void *self, void *arg)
{
    extern unsigned char lbl_27_data_64A0[];
    extern const float lbl_27_rodata_7E8;

    unsigned char *p = (unsigned char *)self;
    void *data = lbl_27_data_64A0;
    float value = lbl_27_rodata_7E8;

    *(void **)(p + 0x08) = data;
    p[0x04] = 0;
    *(void **)(p + 0x00) = (unsigned char *)data + 8;
    *(void **)(p + 0x0C) = arg;
    *(float *)(p + 0x10) = value;
    p[0x14] = 0;
}
