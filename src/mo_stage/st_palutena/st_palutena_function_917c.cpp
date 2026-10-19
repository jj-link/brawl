#pragma force_active on
extern "C" {
void fn_67_917C(char *self, float *out)
{
    if (out == 0) {
        return;
    }
    out[0] = *(float *)(self + 0x1dc);
    out[1] = *(float *)(self + 0x1e0);
    out[2] = *(float *)(self + 0x1e4);
}
}
