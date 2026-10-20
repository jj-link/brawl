#pragma force_active on
extern "C" void* fn_27_1B02B4(char* self, int idx)
{
    int i = (*(int*)(self + 8) >> 30) + idx;
    if (i >= 1) {
        i = i - 1;
    }
    return self + (i << 4) + 0xC;
}
