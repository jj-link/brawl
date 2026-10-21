#pragma force_active on

struct S
{
    int pad : 2;
    signed int field : 2;
};

extern "C" int fn_79_468C(void *p)
{
    return ((S *)((char *)p + 8))->field;
}
