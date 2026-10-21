#pragma force_active on
extern "C" void* fn_802CEE90(void* src, void* dst)
{
    float* in = (float*)src;
    float* out = (float*)dst;
    out[0] = in[4];
    out[1] = in[5];
    out[2] = in[6];
    out[3] = in[7];
    out[4] = in[8];
    out[5] = in[9];
    out[6] = in[10];
    out[7] = in[11];
    return dst;
}
