#pragma force_active on
typedef struct Holder {
    int pad[2];
    unsigned int word;
} Holder;

extern "C" int fn_62_A624(Holder *h)
{
    int x = h->word << 4;
    return (x & (int)0xE0000000) >> 30;
}
