#pragma force_active on
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

extern "C" {
void fn_41_1592C(Vec2 *a, Vec2 *b) {
    a->x = a->x + b->x;
    a->y = a->y + b->y;
}
}
