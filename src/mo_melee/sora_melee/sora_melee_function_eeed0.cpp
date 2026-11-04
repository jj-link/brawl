#pragma force_active on

struct Data {
    int a;
    int b;
    int c;
    char d;
    char e;
    char f;
    char g;
    int h;
    int i;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_EEED0(Container* self, int start, const Data* source, unsigned int countArg)
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
        dst->h = source->h;
        dst->i = source->i;
    }
}