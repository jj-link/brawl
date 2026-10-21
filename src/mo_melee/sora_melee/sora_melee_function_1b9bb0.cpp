#pragma force_active on

struct Triple {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct Container {
    virtual void slot08();
    virtual Triple* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1B9BB0(Container* self, int start, const Triple* value,
                             unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Triple* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
    }
}
