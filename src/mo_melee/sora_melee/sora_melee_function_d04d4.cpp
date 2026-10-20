#pragma force_active on
struct fn27Obj {
    int pad[2];
    unsigned int f : 7;
    unsigned int g : 25;
};

extern "C" void fn_27_D04D4(fn27Obj* p, unsigned int v)
{
    p->f = v;
}
