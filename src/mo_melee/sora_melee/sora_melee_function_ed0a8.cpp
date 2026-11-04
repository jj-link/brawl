#pragma force_active on

struct Data {
    char a;
    int b;
    int c;
    char d;
    char e;
    int f;
    int g;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_ED0A8(Container* self, int start, const Data* source, unsigned int countArg)
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
        dst->e = source->e;
        dst->f = source->f;
        dst->g = source->g;
    }
}