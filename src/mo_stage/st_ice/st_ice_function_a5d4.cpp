#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int top : 2;
    unsigned int rest : 30;
};

extern "C" {
void fn_62_A5D4(struct Obj *p, unsigned int v)
{
    p->top = v;
}
}
