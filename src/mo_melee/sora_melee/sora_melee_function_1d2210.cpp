#pragma force_active on

struct Entry {
    unsigned int a;
    unsigned int b;
    short c;
    short d;
};

struct Container {
    virtual void slot08();
    virtual Entry* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1D2210(Container* self, int start, const Entry* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->size()) {
        count = self->size() - start;
    }
    for (int i = 0; i < count; ++i) {
        Entry* dst = self->at(start + i);
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
    }
}
