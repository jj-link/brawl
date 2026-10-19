#pragma force_active on
struct Bits
{
    unsigned int pad : 6;
    signed int field : 6;
};

extern "C" int fn_79_4350(void *p)
{
    return ((Bits *)((char *)p + 8))->field;
}
