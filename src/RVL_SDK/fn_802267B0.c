#include <types.h>
#pragma force_active on

extern f32 lbl_8059ED58;

typedef struct Point {
    f32 x;
    f32 y;
    s8 flag8;
    s8 flag9;
    u8 pad[2];
} Point;

typedef struct Obj {
    u8 pad00[0x5E];
    s8 f5E;
    u8 pad5F[0xB0 - 0x5F];
    f32 fB0;
    f32 fB4;
    u8 padB8[0xC4 - 0xB8];
    Point pts[6];
    u8 pad10C[0x490 - 0x10C];
    f32 f490;
    f32 f494;
    f32 f498;
    u8 pad49C[0x4B8 - 0x49C];
    f32 f4B8;
    f32 f4BC;
} Obj;

s32 fn_802267B0(Obj* obj) {
    Point* outer;
    Point* inner;
    Point* bestA;
    Point* bestB;
    f32 best;
    f32 dx;
    f32 dy;
    f32 d2;
    f32 vx;
    f32 vy;
    f32 fx;
    f32 fy;
    f32 ty;

    best = lbl_8059ED58 * lbl_8059ED58;
    outer = &obj->pts[4];
    do {
        if (outer->flag8 == 0 && outer->flag9 == 0) {
            inner = &obj->pts[0];
            do {
                if (inner->flag8 == 0) {
                    dx = outer->x - inner->x;
                    dy = outer->y - inner->y;
                    d2 = dx * dx + dy * dy;
                    if (d2 < best) {
                        best = d2;
                        bestA = outer;
                        bestB = inner;
                    }
                }
                inner++;
            } while (inner < &obj->pts[4]);
        }
        outer++;
    } while (outer < &obj->pts[6]);

    if (best == lbl_8059ED58 * lbl_8059ED58) {
        return 0;
    }

    *bestA = *bestB;

    vx = obj->fB0 * obj->f4B8 + obj->fB4 * obj->f4BC;
    vy = obj->fB4 * obj->f4B8 - obj->fB0 * obj->f4BC;
    fx = obj->f490 * vx;
    obj->f494 = vx;
    fy = obj->f490 * vy;
    obj->f498 = vy;

    if (bestA == &obj->pts[4]) {
        obj->pts[5].x = bestA->x + fx;
        ty = bestA->y + fy;
        obj->pts[5].flag8 = 0;
        obj->pts[5].flag9 = -1;
        obj->pts[5].y = ty;
    } else {
        obj->pts[4].x = bestA->x - fx;
        ty = bestA->y - fy;
        obj->pts[4].flag8 = 0;
        obj->pts[4].flag9 = -1;
        obj->pts[4].y = ty;
    }

    if ((s8) obj->f5E < 0) {
        return -1;
    }
    return 1;
}
