#pragma force_active on

struct Elem {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot00();
    virtual Elem* at(int index);
    virtual void slot08();
    virtual int size();
};

extern "C" void fn_27_10259C(Container* self, int start, const Elem* source,
                           unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Elem* dst = self->at(start + i);
        *dst = *source;
    }
}
