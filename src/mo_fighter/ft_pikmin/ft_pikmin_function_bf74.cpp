#pragma force_active on
struct Vec2f { float x; float y; };

extern "C" float fn_113_BF74(const Vec2f* vector) {
    return vector->x * vector->x + vector->y * vector->y;
}
