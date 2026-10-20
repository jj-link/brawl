#pragma force_active on
extern "C" void* fn_27_295BEC(char* self, int idx)
{
    int v = *(int*)(self + 8) >> 29;
    int i = v + idx;
    if (i >= 3) {
        i -= 3;
    }
    return self + i * 0xa0 + 0xc;
}
