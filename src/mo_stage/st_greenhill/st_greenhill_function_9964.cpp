#pragma force_active on

struct Pair {
    unsigned int a;
    unsigned int b;
};

struct Container {
    virtual void slot08();
    virtual Pair* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_72_9964(Container* self, int start, const Pair* value,
                           unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Pair* dst = self->at(start + i);
        *dst = *value;
    }
}
