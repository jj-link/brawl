#pragma force_active on
extern "C" void fn_66_11300(void *self, unsigned int v)
{
    struct S {
        unsigned int pad[2];
        unsigned int a : 3;
        unsigned int rest : 29;
    } *s = (struct S *)self;
    s->a = v;
}
