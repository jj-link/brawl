#pragma force_active on

struct Data {
    int a;
    int b;
    int c;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1DBD0(Container* self, int start, const Data* value, unsigned int count) {
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        Data* dst = self->at(start + i);
        if (dst != value) {
            int c = value->c;
            int b = value->b;
            int a = value->a;
            dst->a = a;
            dst->b = b;
            dst->c = c;
        }
    }
}
