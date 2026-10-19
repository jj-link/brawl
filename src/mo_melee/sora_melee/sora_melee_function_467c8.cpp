#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Input {
    Vec3 a;
    Vec3 b;
    float value;
    unsigned int index : 9;
    unsigned int flag : 1;
    unsigned int unused : 22;
    unsigned char pad[0x3c];
    int enabled;
};

struct Output {
    unsigned char pad[0x24];
    bool valid;
};

extern "C" void fn_27_55874(
    void*, Output*, unsigned int, int, unsigned int,
    const Vec3*, const Vec3*, int, int, float, float);

extern "C" bool fn_27_467C8(
    Input* self, void* context, Output* output, float value)
{
    if (self->enabled) {
        Vec3 a(self->a);
        Vec3 b(self->b);
        fn_27_55874(context, output, self->flag, 0, self->index,
                    &a, &b, 0, 0, self->value, value);
        output->valid = true;
        return true;
    }

    output->valid = false;
    return false;
}
