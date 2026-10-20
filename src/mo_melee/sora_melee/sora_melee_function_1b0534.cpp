#pragma force_active on
struct Entry {
    unsigned char data[0x68];
};

extern "C" Entry *fn_27_1B0534(int *this_, int index)
{
    int offset = this_[2] >> 27;
    int sum = offset + index;
    if (sum >= 11)
        sum -= 11;
    return reinterpret_cast<Entry *>(reinterpret_cast<char *>(this_) + sum * 0x68 + 0x0C);
}
