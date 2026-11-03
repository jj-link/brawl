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
class Class_1FA8 {
public:
    virtual void fn_51_8C18();
    virtual Data* fn_51_80E0(int);
    virtual void fn_51_80F0();
    virtual int fn_51_65D8();
};
class Class_2250 {
public:
    virtual void fn_51_A60C();
    virtual Data* fn_51_9A2C(int);
    virtual void fn_51_9A3C();
    virtual int fn_51_6738();
};
class Class_40B8 {
public:
    virtual void fn_51_8C18();
    virtual Data* fn_51_80E0(int);
    virtual void fn_51_80F0();
    virtual int fn_51_DA64();
};
extern "C" void fn_51_7E6C(Class_1FA8* self, int start, const Data* src, unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_51_65D8())
        count = self->fn_51_65D8() - start;
    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_51_80E0(start + i);
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