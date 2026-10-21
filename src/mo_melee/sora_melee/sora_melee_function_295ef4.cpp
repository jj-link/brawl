#pragma force_active on

struct Obj {
    unsigned int pad : 6;
    unsigned int field : 3;
    unsigned int rest : 23;
};

extern "C" void fn_27_295EF4(void* p, unsigned int v)
{
    Obj* o = (Obj*)((char*)p + 8);
    o->field = v;
}
