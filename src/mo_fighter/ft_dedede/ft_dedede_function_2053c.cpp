#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

extern "C" Vec2 fn_117_2053C(const Vec2* value, float scale) {
    Vec2 result;
    result.x = value->x * scale;
    result.y = value->y * scale;
    return result;
}
