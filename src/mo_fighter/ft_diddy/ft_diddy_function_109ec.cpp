#pragma force_active on
struct FloatPair {
    float x;
    float y;
};

extern "C" {
void fn_115_109EC(FloatPair* object, float x, float y) {
    object->x = x;
    object->y = y;
}
}
