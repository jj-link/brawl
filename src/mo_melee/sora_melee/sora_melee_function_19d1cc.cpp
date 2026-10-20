#pragma force_active on
typedef unsigned int u32;

struct Field
{
    unsigned int value : 4;
    unsigned int reserved : 28;
};

extern "C" void fn_27_19D1CC(void *p1, u32 p2)
{
    ((Field *)((char *)p1 + 8))->value = p2;
}
