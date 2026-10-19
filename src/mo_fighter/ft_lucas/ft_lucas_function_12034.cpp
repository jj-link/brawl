#pragma force_active on
extern "C" struct Vec2 {
    float x;
    float y;
};

extern "C" Vec2 fn_114_12034(const Vec2* v, float s) {
    Vec2 result;
    result.x = v->x * s;
    result.y = v->y * s;
    return result;
}
