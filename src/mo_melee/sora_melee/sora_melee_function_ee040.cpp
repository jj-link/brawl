#pragma force_active on

struct Data {
    int a;
};

struct Container {
    virtual void slot00();
    virtual Data* at(int index);
    virtual void slot0C();
    virtual int size();
};

extern "C" void fn_27_EE040(Container* self, int start, Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        *self->at(start + i) = *source;
    }
}
