#include <types.h>
#pragma force_active on

typedef struct Vec2 {
    f32 x;
    f32 y;
} Vec2;

typedef struct Point {
    f32 x;
    f32 y;
    s8 flag8;
    s8 flag9;
    u8 pad[2];
} Point;

typedef struct Obj {
    u8 pad00[0xB0];
    f32 fB0;
    f32 fB4;
    u8 padB8[0xC4 - 0xB8];
    Point pts[6];
    u8 pad10C[0x4A0 - 0x10C];
    f32 f4A0;
    u8 pad4A4[0x4B8 - 0x4A4];
    f32 f4B8;
    f32 f4BC;
    u8 pad4C0[0x4F4 - 0x4C0];
    f32 f4F4;
    f32 f4F8;
    f32 f4FC;
    f32 f500;
} Obj;

s32 fn_802265FC(Obj* obj) {
    Point* p;
    f32 s[4];
    f32 offX;
    f32 offY;

    p = &obj->pts[0];

    offX = obj->fB0 * obj->f4B8 + obj->fB4 * obj->f4BC;
    offY = obj->fB4 * obj->f4B8 - obj->fB0 * obj->f4BC;
    offX *= obj->f4A0;
    offY *= obj->f4A0;

    do {
        if (p->flag8 == 0) {
            s[2] = p->x - offX;
            s[3] = p->y - offY;
            s[0] = p->x + offX;
            s[1] = p->y + offY;
            if (s[2] <= obj->f4F4 || s[2] >= obj->f4FC || s[3] <= obj->f4F8 || s[3] >= obj->f500) {
                if (s[0] > obj->f4F4 && s[0] < obj->f4FC && s[1] > obj->f4F8 && s[1] < obj->f500) {
                    obj->pts[5] = *p;
                    *(Vec2*)&obj->pts[4].x = *(Vec2*)&s[2];
                    obj->pts[4].flag8 = 0;
                    obj->pts[4].flag9 = -1;
                    return -1;
                }
            } else {
                if (s[0] <= obj->f4F4 || s[0] >= obj->f4FC || s[1] <= obj->f4F8 || s[1] >= obj->f500) {
                    obj->pts[4] = *p;
                    *(Vec2*)&obj->pts[5].x = *(Vec2*)&s[0];
                    obj->pts[5].flag8 = 0;
                    obj->pts[5].flag9 = -1;
                    return -1;
                }
            }
        }
        p++;
    } while (p < &obj->pts[4]);
    return 0;
}
