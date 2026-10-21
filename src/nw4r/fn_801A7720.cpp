#pragma force_active on
extern "C" void fn_801A7720(char **arg0, float *out)
{
    if (out == 0) {
        return;
    }
    char *ptr = *arg0;
    if (ptr == 0) {
        return;
    }
    out[0] = *(float *)(ptr + 0x74);
    out[1] = *(float *)(ptr + 0x78);
    out[2] = *(float *)(ptr + 0x7c);
}
