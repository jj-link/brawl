#pragma force_active on
struct Vec2f { float x; float y; };

extern "C" void fn_102_C5AC(Vec2f* v, float x, float y) {
    v->x = x;
    v->y = y;
}
