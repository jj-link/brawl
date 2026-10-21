#pragma force_active on

struct Data {
    unsigned int a;
    float b, c, d, e, f;
    unsigned char g;
    unsigned int h, i;
    float j, k, l, m, n;
    unsigned char o;
    unsigned int p, q;
    unsigned char r;
};

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual Data* getData(unsigned int);
};

extern "C" Data* fn_27_EC9B0(Base* self, unsigned int a, unsigned int b)
{
    Data* src = self->getData(a);
    Data* dst = self->getData(b);
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
    return dst;
}
