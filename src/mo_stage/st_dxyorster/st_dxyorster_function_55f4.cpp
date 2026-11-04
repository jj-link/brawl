#pragma force_active on

struct Data {
    int a;
    short b;
    short c;
    float d;
    float e;
    int f;
    float g;
    float h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};

class Class_1AB0 {
public:
    virtual void fn_76_6F4C();
    virtual Data* fn_76_6414(int);
    virtual void fn_76_6424();
    virtual int fn_76_3F88();
};

extern "C" void fn_76_55F4(Class_1AB0* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_76_3F88())
        count = self->fn_76_3F88() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_76_6414(start + i);
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
        dst->e = src->e;
        dst->f = src->f;
        dst->g = src->g;
        dst->h = src->h;
        dst->i = src->i;
        dst->j = src->j;
        dst->k = src->k;
        dst->l = src->l;
        dst->m = src->m;
        dst->n = src->n;
        dst->o = src->o;
        dst->p = src->p;
        dst->q = src->q;
        dst->r = src->r;
    }
}
