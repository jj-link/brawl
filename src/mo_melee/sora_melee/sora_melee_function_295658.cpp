#pragma force_active on
struct FieldWord {
    unsigned int top : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_295658(void *self, unsigned int val)
{
    FieldWord *p = (FieldWord *)((char *)self + 8);
    p->top = val;
}
