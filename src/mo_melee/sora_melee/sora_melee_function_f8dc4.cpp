#pragma force_active on
extern "C" int* fn_27_F8DC4(int* base, int offset)
{
    int index = (base[6] >> 26) + offset;
    if (index >= 0x17)
        index -= 0x17;
    return reinterpret_cast<int*>(reinterpret_cast<char*>(base) + index * 0xC + 0x1C);
}
