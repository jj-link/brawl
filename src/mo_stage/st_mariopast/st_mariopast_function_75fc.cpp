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

extern "C" void fn_48_75FC(Container* self, int start,
                           const Pair* value, unsigned int count) {
    int limit = static_cast<int>(count);

    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }

    for (count = 0; static_cast<int>(count) < limit; ++count) {
        *self->at(start + static_cast<int>(count)) = *value;
    }
}
