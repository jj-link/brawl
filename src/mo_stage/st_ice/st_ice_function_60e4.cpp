#pragma force_active on
struct BitObj {
    int pad[2];
    unsigned int hi : 3;
    unsigned int rest : 29;
};

extern "C" void fn_62_60E4(BitObj *p, unsigned int v)
{
    p->hi = v;
}
