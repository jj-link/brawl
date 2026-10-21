#pragma force_active on

struct Pair {
    void* ptr;
    int value;
};

struct Container {
    virtual void unused();
    virtual Pair* get(int index);
    virtual void unused2();
    virtual int size();
};

extern "C" void fn_74_A2CC(Container* self, int start, const Pair* source,
                           unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        *self->get(start + i) = *source;
    }
}
