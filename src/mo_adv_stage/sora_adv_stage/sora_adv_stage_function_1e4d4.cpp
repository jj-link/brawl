#pragma force_active on
struct GrBits {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int mode : 6;
    unsigned int rest : 26;
};

extern "C" void fn_40_1E4D4(GrBits* p, unsigned int v)
{
    p->mode = v;
}
