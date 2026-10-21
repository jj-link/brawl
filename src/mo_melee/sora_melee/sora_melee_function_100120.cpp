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
    virtual void unused2();
    virtual int size();
};

extern "C" void fn_27_100120(Container* self, int start, const Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;
    for (int i = 0; i < count; ++i) {
        *static_cast<Data*>(self->at(start + i)) = *source;
    }
}
