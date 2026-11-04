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

class Class_15E0 {
public:
    virtual void fn_72_7748();
    virtual Data* fn_72_6C10(int);
    virtual void fn_72_6C20();
    virtual int fn_72_5108();
};

class Class_1888 {
public:
    virtual void fn_72_913C();
    virtual Data* fn_72_855C(int);
    virtual void fn_72_856C();
    virtual int fn_72_5268();
};

class Class_3028 {
public:
    virtual void fn_72_7748();
    virtual Data* fn_72_6C10(int);
    virtual void fn_72_6C20();
    virtual int fn_72_BF34();
};

class Class_33D0 {
public:
    virtual void fn_72_913C();
    virtual Data* fn_72_855C(int);
    virtual void fn_72_856C();
    virtual int fn_72_BFCC();
};

extern "C" void fn_72_699C(Class_15E0* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_72_5108())
        count = self->fn_72_5108() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_72_6C10(start + i);
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
