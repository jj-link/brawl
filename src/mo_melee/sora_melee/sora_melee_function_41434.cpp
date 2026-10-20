#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Object {
    unsigned char pad0[0x40];
    Vec2 position;
    unsigned char pad48[0x54];
    unsigned int flags;
};

extern "C" void fn_27_41434(Object* self, const Vec2* position)
{
    self->position = *position;
    self->flags &= ~0x20000000u;
}
