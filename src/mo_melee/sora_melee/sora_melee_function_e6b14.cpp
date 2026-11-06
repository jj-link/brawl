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
class Class_20958 {
public:
    virtual void fn_27_C76A8();
    virtual Data* fn_27_C7528(int);
    virtual void fn_27_C7538();
    virtual int size__41soArrayContractibleTable();
};
extern "C" void fn_27_E6B14(Class_20958* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->size__41soArrayContractibleTable())
        count = self->size__41soArrayContractibleTable() - start;
    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_27_C7528(start + i);
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