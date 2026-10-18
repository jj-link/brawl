#pragma force_active on
extern "C" int fn_48_1080(void *object, int *unused, int *outType, int *outValue)
{
    unsigned char *bytes = (unsigned char *)object;

    if (bytes[0x30F] == 0)
        return 0;

    float *current = (float *)(bytes + 0x318);
    float *value = (float *)(bytes + 0x2A0);
    extern const float lbl_48_rodata_0;

    if (*current > lbl_48_rodata_0 && *value <= lbl_48_rodata_0)
    {
        *outType = 6;
        *outValue = 4;
        return 1;
    }

    *current = *value;
    return 0;
}
