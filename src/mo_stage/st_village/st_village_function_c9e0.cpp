#pragma force_active on
struct Pair {
    int a;
    int b;
};

struct Container {
    virtual void unused0();
    virtual Pair* get(int index);
    virtual void unused2();
    virtual int size();
};

extern "C" void fn_70_C9E0(Container* self, int start, const Pair* value, unsigned int count) {
    int limit = static_cast<int>(count);

    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }

    for (count = 0; static_cast<int>(count) < limit; ++count) {
        Pair* dst = self->get(start + static_cast<int>(count));
        *dst = *value;
    }
}
