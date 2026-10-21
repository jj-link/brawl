#pragma force_active on

struct S
{
    unsigned int pad : 12;
    signed int field : 6;
};

extern "C" int fn_79_59DC(void *p)
{
    return ((S *)((char *)p + 8))->field;
}
