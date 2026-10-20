#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_22C230(char* base, float* out, u32 idx)
{
    if (idx >= 12) {
        return;
    }
    float* src = (float*)(base + idx * 12 + 0x1d8);
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
}
