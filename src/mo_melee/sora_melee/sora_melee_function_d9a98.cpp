#pragma force_active on
extern "C" int *fn_27_D9A98(int *p, int index)
{
    int slot = (p[2] >> 26) + index;

    if (slot >= 0x11)
        slot -= 0x11;

    return reinterpret_cast<int *>(reinterpret_cast<char *>(p) + slot * 0x24 + 0x0C);
}
