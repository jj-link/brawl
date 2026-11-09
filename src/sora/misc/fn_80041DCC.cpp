#include <nw4r/math/math_types.h>
#pragma force_active on
struct Rect { float x0, y0, x1, y1; };
struct Circle { float x, y, r; };
extern "C" int fn_80041DCC(const Rect* a, const Circle* b) {
    float bx = b->x, by = b->y, br = b->r;
    int r = 0;
    do {
        if (a->x1 < bx - br || a->y1 < by - br || a->x0 > bx + br || a->y0 > by + br) break;
        r = 1;
        if (a->x1 >= bx && a->x0 <= bx) break;
        if (a->y1 >= by && a->y0 <= by) break;
        float rr = br * br;
        if (a->x0 > bx) {
            float dx = bx - a->x0;
            if (a->y1 < by) {
                nw4r::math::VEC2 v(dx, by - a->y1);
                if (v.x * v.x + v.y * v.y < rr) break;
            }
            if (by < a->y0) {
                nw4r::math::VEC2 v(dx, by - a->y0);
                if (v.x * v.x + v.y * v.y < rr) break;
            }
        } else if (a->x1 < bx) {
            float dx = bx - a->x1;
            if (a->y1 < by) {
                nw4r::math::VEC2 v(dx, by - a->y1);
                if (v.x * v.x + v.y * v.y < rr) break;
            }
            if (by < a->y0) {
                nw4r::math::VEC2 v(dx, by - a->y0);
                if (v.x * v.x + v.y * v.y < rr) break;
            }
        }
        r = 0;
    } while (0);
    return r;
}
