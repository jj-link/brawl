#pragma force_active on
struct Container {
    virtual void slot00();
    virtual float* at(int index);
    virtual void slot08();
    virtual int size();
};

extern "C" void fn_103_FC18(Container* self, int start, const float* value, unsigned int count) {
    int limit = static_cast<int>(count);

    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }

    for (count = 0; static_cast<int>(count) < limit; ++count) {
        float v = *value;
        *self->at(start + static_cast<int>(count)) = v;
    }
}
