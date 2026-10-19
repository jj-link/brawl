#pragma force_active on
extern "C" {
extern const float lbl_41_rodata_DC4;
}

extern "C" float fn_41_2AFF8(const float* arg0)
{
    float prod = lbl_41_rodata_DC4 * arg0[10];
    return prod + arg0[11];
}
