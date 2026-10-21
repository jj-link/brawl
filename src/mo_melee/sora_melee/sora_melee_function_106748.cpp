#pragma force_active on

struct Data {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void unused0();
    virtual Data* at(int index);
    virtual void unused1();
    virtual int size();
};

extern "C" void fn_27_106748(Container* self, int start, const Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;
    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
    }
}
