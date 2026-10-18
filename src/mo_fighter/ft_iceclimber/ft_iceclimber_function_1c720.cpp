#pragma force_active on
struct Vec2Pair {
    float x;
    float y;
};

struct Holder {
    unsigned int header[2];
    float x;
    float y;
};

extern "C" void fn_105_1C720(Holder* obj, const Vec2Pair* src) {
    obj->x = src->x;
    obj->y = src->y;
}
