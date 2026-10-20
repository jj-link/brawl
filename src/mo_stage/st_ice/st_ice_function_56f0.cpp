#pragma force_active on
typedef struct Holder {
    int pad[2];
    unsigned int word;
} Holder;

extern "C" int fn_62_56F0(Holder *h)
{
    return (int)((h->word << 3) & 0xF0000000u) >> 29;
}
