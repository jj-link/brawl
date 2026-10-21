#pragma force_active on
struct Bits {
    unsigned int pad[2];
    unsigned int : 8;
    unsigned int field : 4;
    unsigned int rest : 20;
};

extern "C" void fn_47_4FB4(Bits *p, unsigned int v)
{
    p->field = v;
}
