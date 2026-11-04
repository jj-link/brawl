#pragma force_active on
struct Data {
    int a;
    short b, c;
    float d, e;
    int f;
    float g, h;
    int i, j, k, l, m;
    unsigned char n, o, p, q, r;
};
class Class_25A0 {
public:
    virtual void fn_48_6260();
    virtual Data* fn_48_5728(int);
    virtual void fn_48_5738();
    virtual int fn_48_B6A4();
};
class Class_2968 {
public:
    virtual void fn_48_6260();
    virtual Data* fn_48_5728(int);
    virtual void fn_48_5738();
    virtual int fn_48_B994();
};
class Class_2D30 {
public:
    virtual void fn_48_6260();
    virtual Data* fn_48_5728(int);
    virtual void fn_48_5738();
    virtual int fn_48_BC84();
};
class Class_30F8 {
public:
    virtual void fn_48_6260();
    virtual Data* fn_48_5728(int);
    virtual void fn_48_5738();
    virtual int fn_48_BF74();
};
extern "C" void fn_48_54B4(Class_25A0* self, int start, const Data* src, unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_48_B6A4())
        count = self->fn_48_B6A4() - start;
    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_48_5728(start + i);
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