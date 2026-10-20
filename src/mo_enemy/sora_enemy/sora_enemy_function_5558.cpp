#pragma force_active on
extern "C" const float lbl_41_rodata_8;

struct Vec2 {
    float x, y;

    Vec2(float a, float b) : x(a), y(b) {}
};

struct Object {
    char pad[0xD0];
    Vec2 value;
};

extern "C" void fn_41_5558(Object* self) {
    self->value = Vec2(lbl_41_rodata_8, lbl_41_rodata_8);
}
