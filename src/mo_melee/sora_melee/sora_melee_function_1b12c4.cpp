#pragma force_active on
extern "C" void* fn_27_1B12C4(int* self, int idx)
{
    int n = self[2] >> 30;
    int i = n + idx;
    if (i >= 1) {
        i = i - 1;
    }
    return (char*)self + 0xC + i * 4;
}
