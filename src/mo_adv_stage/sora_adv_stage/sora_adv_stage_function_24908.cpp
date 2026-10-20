#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int mode : 2;
    unsigned int rest : 30;
};

extern "C" void fn_40_24908(Obj* p, unsigned int v)
{
    p->mode = v;
}
