#pragma force_active on
extern "C" char* fn_68_6464(char* self, int index)
{
    int n = *(int*)(self + 8) >> 30;
    int i = n + index;
    if (i >= 1) {
        i = i - 1;
    }
    return self + i * 120 + 12;
}
