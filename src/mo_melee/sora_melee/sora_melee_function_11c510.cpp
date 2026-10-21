#pragma force_active on

struct Data {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot00();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_11C510(Container* self, int start, const Data* source, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        Data* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
    }
}
