#pragma force_active on

struct Container {
    virtual void slot08();
    virtual float* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_DC960(Container* self, int start, const float* source, unsigned int count) {
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        *self->at(start + i) = *source;
    }
}
