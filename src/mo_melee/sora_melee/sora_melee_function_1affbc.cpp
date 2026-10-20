#pragma force_active on
struct Obj
{
    int pad[2];
    int field;
};

extern "C" void* fn_27_1AFFBC(Obj* p, int i)
{
    int n = (p->field >> 29) + i;
    if (n >= 2)
        n -= 2;
    return (char*)p + n * 12 + 12;
}
