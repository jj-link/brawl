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

struct Object {
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
    virtual Data* get(int);
};

extern "C" void fn_66_BE5C(Object* obj, int from, int to) {
    Data* src = obj->get(from);
    Data* dst = obj->get(to);
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
