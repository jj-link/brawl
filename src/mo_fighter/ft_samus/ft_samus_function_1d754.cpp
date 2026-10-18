#pragma force_active on
struct Flags {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 6;
};

extern "C" bool fn_94_1D754(void *self)
{
    return ((Flags *)((unsigned char *)self + 0xa4))->b;
}
