#pragma force_active on
struct S {
    unsigned char pad[0x34];
    unsigned char a : 5;
    unsigned char flag : 1;
    unsigned char b : 2;
};

extern "C" bool fn_27_6A214(S* p)
{
    return p->flag;
}
