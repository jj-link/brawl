#pragma force_active on
extern "C" void fn_51_25FC(void *self, float *out)
{
    if (out == 0) {
        return;
    }
    out[0] = *(float *)((char *)self + 0x3a0);
    out[1] = *(float *)((char *)self + 0x3a4);
    out[2] = *(float *)((char *)self + 0x3a8);
}
