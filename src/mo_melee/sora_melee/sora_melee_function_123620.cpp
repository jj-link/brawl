#pragma force_active on

struct Data {
    int a;
    int b;
    int c;
    int d;
};

struct Container {
    virtual void slot0();
    virtual Data* at(int index);
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_123620(Container* self, int start, const Data* source, unsigned int countArg) {
    int limit = static_cast<int>(countArg);
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
