#pragma force_active on

struct Data {
    int a;
    int b;
    float c;
    union {
        int d;
        char bytes[4];
    };
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1B371C(Container* self, int start, const Data* value, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        Data* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
        dst->d = value->d;
        dst->bytes[1] = value->bytes[1];
    }
}
