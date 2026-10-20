#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int field;
};

extern "C" void fn_27_D1C6C(Obj* p, unsigned int value)
{
    p->field = __rlwimi(p->field, value, 20, 6, 11);
}
