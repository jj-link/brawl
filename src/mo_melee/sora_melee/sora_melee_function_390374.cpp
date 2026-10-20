#pragma force_active on
struct FieldWord {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
};

extern "C" void fn_27_390374(void *self, unsigned int v)
{
    struct FieldWord *w = (struct FieldWord *)((char *)self + 8);
    w->b = v;
}
