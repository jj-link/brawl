#pragma force_active on

struct Data {
    int a;
    int b;
    int c;
    float d;
};

struct Container {
    ~Container() {}
    virtual void slot00();
    virtual Data* at(int index);
    virtual void slot08();
    virtual int size();
};

extern "C" void fn_27_1B4D10(Container* self, int start, const Data* source, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        *static_cast<Data*>(self->at(start + i)) = *source;
    }
}
