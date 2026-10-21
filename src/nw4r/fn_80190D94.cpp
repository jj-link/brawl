#pragma force_active on
extern "C" char* fn_80190D94(char** base, int index)
{
    if (*base != 0 && index >= 0 && index <= 7)
        return *base + index * 0xC + 4;
    return 0;
}
