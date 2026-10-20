#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
};

extern "C" void fn_51_D7E8(struct Obj *p, int v)
{
    p->b = v;
}
