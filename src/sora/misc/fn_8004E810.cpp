#pragma force_active on
typedef unsigned int u32;

struct Inner {
    u32 pad[154];
    u32 field;
};

struct Outer {
    u32 pad[9];
    Inner *ptr;
};

extern "C" u32 fn_8004E810(Outer *p)
{
    return (p->ptr->field >> 2) & 1;
}
