#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int word;
};

extern "C" void fn_76_3F48(S *p, unsigned int value)
{
    p->word = __rlwimi(p->word, value, 22, 5, 9);
}
