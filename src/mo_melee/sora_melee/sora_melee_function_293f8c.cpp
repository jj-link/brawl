#pragma force_active on
extern "C" void* fn_27_293F8C(char* p, int idx)
{
    int s = *(int*)(p + 0x18) >> 27;
    int t = s + idx;
    if (t >= 9) {
        t = t - 9;
    }
    return p + t * 12 + 0x1c;
}
