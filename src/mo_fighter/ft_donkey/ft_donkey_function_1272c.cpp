#pragma force_active on
struct Fn92Bits {
    unsigned char pad[0xa4];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char rest : 6;
};

extern "C" bool fn_92_1272C(void* p)
{
    return ((Fn92Bits*)p)->b1;
}
