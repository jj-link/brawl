#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

class Container {
public:
    virtual void reserved08();
    virtual Vec2* get(int index);
    virtual void reserved10();
    virtual int size();
};

extern "C" void fn_113_BC00(Vec2* dst, const Vec2* src);

extern "C" void fn_113_12328(
    Container* self, int start, const Vec2* value, unsigned int count)
{
    int limit = static_cast<int>(count);

    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }

    for (count = 0; static_cast<int>(count) < limit; ++count) {
        fn_113_BC00(self->get(start + count), value);
    }
}
