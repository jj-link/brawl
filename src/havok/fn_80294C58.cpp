#pragma force_active on
#pragma fp_contract on
extern "C" {
float fn_80294C58(const float* a, const float* b)
{
    return a[2] * b[2] + (a[0] * b[0] + a[1] * b[1]);
}
}
