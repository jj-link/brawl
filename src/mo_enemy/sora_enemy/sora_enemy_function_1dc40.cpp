#pragma force_active on
typedef struct {
    float x;
    float y;
} Vec2;

extern "C" int fn_41_1DC40(const Vec2* a, const Vec2* b) {
    int r;
    float ax = a->x;
    r = 0;
    if (ax != b->x) {
        goto set;
    }
    if (a->y == b->y) {
        goto end;
    }
set:
    r = 1;
end:
    return r;
}
