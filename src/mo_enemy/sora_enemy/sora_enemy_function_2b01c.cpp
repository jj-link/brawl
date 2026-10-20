#pragma force_active on
struct FlagBits
{
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
};

extern "C" bool fn_41_2B01C(unsigned char* p)
{
    return ((FlagBits*)(p + 0x34))->f;
}
