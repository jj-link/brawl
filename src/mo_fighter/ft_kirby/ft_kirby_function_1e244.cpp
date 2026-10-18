#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    int value;
};

extern "C" int fn_96_1E244(Obj *p)
{
    return p->value >> 28;
}
