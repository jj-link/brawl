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

class Class_3790 {
public:
    virtual void fn_70_B644();
    virtual Data* fn_70_AB0C(int);
    virtual void fn_70_AB1C();
    virtual int fn_70_9164();
};

extern "C" void fn_70_A898(Class_3790* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_70_9164())
        count = self->fn_70_9164() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_70_AB0C(start + i);
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