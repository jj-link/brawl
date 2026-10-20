#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int flags : 3;
    unsigned int rest : 29;
};

extern "C" void fn_51_DA14(Obj* obj, unsigned int v)
{
    obj->flags = v;
}
