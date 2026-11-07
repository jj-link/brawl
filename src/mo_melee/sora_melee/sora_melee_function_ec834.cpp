#pragma force_active on
struct Elem {
    unsigned int a;
    float b, c, d, e, f;
    unsigned char g;
    unsigned int h, i;
    float j, k, l, m, n;
    unsigned char o;
    unsigned int p, q;
    unsigned char r;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Elem* slot1(int);
    virtual void slot2();
    virtual int slot3();
};
extern "C" void fn_27_EC834(Object_vptr_0* self, int start, const Elem* source, unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->slot3())
        count = self->slot3() - start;
    for (int i = 0; i < count; ++i) {
        Elem* dst = self->slot1(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
        dst->e = source->e;
        dst->f = source->f;
        dst->g = source->g;
        dst->h = source->h;
        dst->i = source->i;
        dst->j = source->j;
        dst->k = source->k;
        dst->l = source->l;
        dst->m = source->m;
        dst->n = source->n;
        dst->o = source->o;
        dst->p = source->p;
        dst->q = source->q;
        dst->r = source->r;
    }
}