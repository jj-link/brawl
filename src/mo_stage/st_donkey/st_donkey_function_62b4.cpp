#pragma force_active on
struct S
{
    char pad[8];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

extern "C" void fn_50_62B4(S *obj, int val)
{
    obj->b = val;
}
