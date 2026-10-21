#pragma force_active on

struct Vec2 {
    int x;
    int y;
};

struct Container {
    virtual void unused0();
    virtual Vec2* get(int index);
    virtual void unused1();
    virtual int size();
};

extern "C" void fn_62_81F8(Container* self, int start, const Vec2* value,
                           unsigned int count) {
    int limit = static_cast<int>(count);

    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }

    for (int i = 0; i < limit; ++i) {
        Vec2* dst = self->get(start + i);
        dst->x = value->x;
        dst->y = value->y;
    }
}
