#pragma force_active on
extern "C" void fn_41_C1CC(char *self, int idx, float scale)
{
    float *arr = *(float **)(self + 0x14);
    float v = arr[idx];
    arr[idx] = v * scale;
}
