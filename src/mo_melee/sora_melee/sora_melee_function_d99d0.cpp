#pragma force_active on
struct Entry
{
    unsigned char data[0x0C];
};

extern "C" Entry *fn_27_D99D0(const void *object, int index)
{
    int adjustment = *reinterpret_cast<const int *>(
        reinterpret_cast<const char *>(object) + 8) >> 30;
    int selected = adjustment + index;
    if (selected < 1)
        goto done;
    selected -= 1;
done:
    return reinterpret_cast<Entry *>(
        reinterpret_cast<char *>(const_cast<void *>(object)) + selected * 0x44 + 0x0C);
}
