#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int field;
};

extern "C" void fn_76_3F28(Obj *p, unsigned int value)
{
    unsigned int *word = &p->field;
    *word = __rlwimi(*word, value, 17, 10, 14);
}
