#pragma force_active on
struct Flags {
    unsigned int top : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_FE458(void *p, unsigned int v)
{
    Flags *f = (Flags *)((char *)p + 8);
    f->top = v;
}
