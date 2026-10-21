#pragma force_active on
struct Pair {
    int a;
    int b;
};

struct Container {
    virtual void slot08();
    virtual Pair* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_54_AF44(Container* self, int start, const Pair* src, unsigned int countArg)
{
    int count = countArg;
    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i)
        *self->at(start + i) = *src;
}
