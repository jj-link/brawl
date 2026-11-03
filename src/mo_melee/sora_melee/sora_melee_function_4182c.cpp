#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
class Container {
public:
    virtual void unused();
    virtual int* get(int);
};
struct Input {
    int state;
    int pad;
    Vec3 a;
    Vec3 b;
    float value;
    unsigned int index : 9;
    unsigned int unused : 6;
    unsigned int flag : 1;
    unsigned int remaining : 16;
    Container container;
    char padding[0x65 - 0x2c];
    bool enabled;
};
struct Output {
    char pad[0x24];
    bool valid;
};
extern "C" void fn_27_55874(void*, Output*, unsigned int, int, unsigned int,
    const Vec3*, const Vec3*, int, int, float, float);
extern "C" bool fn_27_4182C(Input* self, void* context, Output* output,
    int level, int bit, int extra, int mask, float value)
{
    if (self->state != 3) {
        Vec3 a(self->a);
        Vec3 b(self->b);
        fn_27_55874(context, output, self->flag, !self->enabled, self->index,
                    &a, &b, extra, 0, self->value, value);
        int* p = self->container.get(2);
        *p = (1 << bit) | mask;
        if (self->state > level)
            level = self->state;
        p = self->container.get(4);
        *p = 1 << level;
        output->valid = true;
        self->enabled = true;
        return true;
    }
    self->enabled = false;
    output->valid = false;
    return false;
}