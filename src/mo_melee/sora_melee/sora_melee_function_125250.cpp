#pragma force_active on

struct Data {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

struct Container {
    virtual void slot0();
    virtual Data* at(int index);
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_125250(Container* self, int start, const Data* source, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        *static_cast<Data*>(self->at(start + i)) = *source;
    }
}
