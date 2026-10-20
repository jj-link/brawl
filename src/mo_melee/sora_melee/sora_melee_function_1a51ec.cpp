#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int bits : 3;
};

extern "C" void fn_27_1A51EC(Obj *p, unsigned int value)
{
    p->bits = value;
}
