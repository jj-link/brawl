#pragma force_active on
struct Vec2 {
    float x, y;
};

struct History {
    Vec2 positions[16];
    int values[16];
    int index;
};

extern "C" void fn_27_21FFE4(History* self, const Vec2* position, const int* value)
{
    if (++self->index >= 16)
        self->index = 0;

    self->positions[self->index] = *position;
    self->values[self->index] = *value;
}
