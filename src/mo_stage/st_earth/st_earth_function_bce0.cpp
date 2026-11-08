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

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Data* slot1(int);
    virtual void slot2();
    virtual int slot3();
};

extern "C" void fn_66_BCE0(Object_vptr_0* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->slot3())
        count = self->slot3() - start;
    for (int i = 0; i < count; ++i) {
        Data* dst = self->slot1(start + i);
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
