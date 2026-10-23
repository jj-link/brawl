#pragma force_active on

struct Pair {
    int a;
    int b;
};

struct Container {
    virtual void slot08();
    virtual Pair* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_76_773C(Container* self, int start, const Pair* pair,
                         unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        *self->at(start + i) = *pair;
    }
}
