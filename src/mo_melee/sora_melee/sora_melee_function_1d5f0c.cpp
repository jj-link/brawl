#pragma force_active on

struct Vec3 {
    int a;
    int b;
    int c;
};

struct Container {
    virtual void slot00();
    virtual Vec3* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1D5F0C(Container* self, int start, const Vec3* source, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }
    for (int i = 0; i < limit; ++i) {
        Vec3* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
    }
}
