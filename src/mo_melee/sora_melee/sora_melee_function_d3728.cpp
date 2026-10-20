#pragma force_active on
struct FooBits {
    int pad0;
    int pad1;
    unsigned int top : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_27_D3728(FooBits* p, unsigned int v)
{
    p->top = v;
}
}
