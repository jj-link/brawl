#pragma force_active on
struct Vec2f { float x; float y; };

extern "C" void fn_113_1E5B8(Vec2f* v, float s) {
    v->x *= s;
    v->y *= s;
}
