#pragma force_active on

struct Elem {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char e;
};

struct Container {
    virtual ~Container();
    virtual Elem* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_E7358(Container* self, int start, const Elem* source, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }
    for (int i = 0; i < limit; ++i) {
        Elem* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
        dst->e = source->e;
    }
}
