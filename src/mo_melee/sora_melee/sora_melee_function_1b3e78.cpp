#pragma force_active on

struct Elem {
    int a;
    int b;
    int c;
    float d;
};

struct Container {
    virtual void slot00();
    virtual Elem* at(int index);
    virtual void slot08();
    virtual int size();
};

extern "C" void fn_27_1B3E78(Container* self, int start, const Elem* src, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        Elem* dst = self->at(start + i);
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
    }
}
