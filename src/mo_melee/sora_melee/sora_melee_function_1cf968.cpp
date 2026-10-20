#pragma force_active on
extern "C" char* fn_27_1CF968(char* base, int idx)
{
    int v = *(int*)(base + 8);
    int i = (v >> 26) + idx;
    if (i >= 20) {
        i -= 20;
    }
    return base + i * 12 + 12;
}
