#pragma force_active on
extern "C" int fn_110_12920(unsigned char *p)
{
    struct Flags {
        unsigned char a : 1;
        unsigned char b : 1;
        unsigned char c : 6;
    };
    return ((Flags *)(p + 0xa4))->b != 0;
}
