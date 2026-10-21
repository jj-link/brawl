#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Container {
    virtual void slot0();
    virtual Vec3f* at(int index);
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_1E1F0(Container* self, int start, const Vec3f* value,
                           unsigned int count) {
    int limit = static_cast<int>(count);
    if (limit + start >= self->size())
        limit = self->size() - start;
    for (int i = 0; i < limit; ++i) {
        Vec3f* dst = self->at(start + i);
        dst->x = value->x;
        dst->y = value->y;
        dst->z = value->z;
    }
}
