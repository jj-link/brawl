#pragma force_active on
struct S
{
    unsigned char pad[8];
    unsigned int word;
};

extern "C" int fn_77_3644(S* self)
{
    return ((int)((self->word << 2) & 0xE0000000u)) >> 30;
}
