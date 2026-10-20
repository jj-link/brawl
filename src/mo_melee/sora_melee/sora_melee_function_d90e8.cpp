#pragma force_active on
extern "C" void* fn_27_D90E8(char* p, int idx)
{
    int sh = *(int*)(p + 8) >> 28;
    int t = sh + idx;
    if (t >= 6) {
        t -= 6;
    }
    return p + t * 20 + 12;
}
