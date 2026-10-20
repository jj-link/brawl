#pragma force_active on
struct Entry {
    unsigned char padding[8];
    int value;
};

extern "C" Entry *fn_27_B03D8(Entry *base, int index)
{
    int value = (base->value >> 23) + index;

    if (value >= 0xFF)
        value -= 0xFF;

    return reinterpret_cast<Entry *>(
        reinterpret_cast<char *>(base) + value * 0x0C + 0x0C
    );
}
