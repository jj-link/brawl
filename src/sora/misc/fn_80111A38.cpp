#pragma force_active on
extern "C" void fn_80111A38(void *arg0, float *out0, float *out1, unsigned short *idx)
{
    float *data = *(float **)((unsigned char *)arg0 + 0x10);
    float *pa = (float *)((unsigned char *)data + idx[0] * 0x10);
    float *pb = (float *)((unsigned char *)data + idx[1] * 0x10);
    out0[0] = pa[0];
    out0[1] = pa[1];
    out0[2] = pb[0];
    out0[3] = pb[1];
    out1[0] = pa[2];
    out1[1] = pa[3];
    out1[2] = pb[2];
    out1[3] = pb[3];
}
