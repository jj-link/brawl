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

// Classes this function calls through, from the game's vtables.
class Class_1E10 {
public:
    virtual void fn_74_9ADC();
    virtual Data* fn_74_8FA4(int index);
    virtual void fn_74_8FB4();
    virtual int fn_74_6B18();
};

extern "C" void fn_74_8184(Class_1E10* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_74_6B18())
        count = self->fn_74_6B18() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_74_8FA4(start + i);
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
