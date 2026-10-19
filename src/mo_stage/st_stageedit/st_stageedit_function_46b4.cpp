#pragma force_active on
extern "C" void fn_85_46B4(void *arg0, float *out0, float *out1, unsigned int index)
{
    unsigned char *base = (unsigned char *)arg0;

    if (index >= base[0x1E5])
        return;

    float *entry = *(float **)(base + 0x1F0);
    if (entry == 0)
        return;

    entry = (float *)((unsigned char *)entry + index * 0x18);
    out0[0] = entry[0];
    out0[1] = entry[1];
    out0[2] = entry[2];
    out1[0] = entry[3];
    out1[1] = entry[4];
    out1[2] = entry[5];
}
