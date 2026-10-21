#pragma force_active on

struct Data {
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_E9E18(Container* self, int start,
                            const Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        *self->at(start + i) = *source;
    }
}
