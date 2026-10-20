#pragma force_active on
extern "C" char* fn_27_1B0D0C(char* self, int idx)
{
    int n = *(int*)(self + 8);
    int i = (n >> 27) + idx;
    if (i >= 11) {
        i -= 11;
    }
    return self + (i << 4) + 12;
}
