#pragma force_active on
struct Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int field : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_1D5A8C(Obj* p, unsigned int v)
{
    p->field = v;
}
