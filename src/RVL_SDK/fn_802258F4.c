#pragma force_active on
extern double fn_80400D94(double);

extern float lbl_8059ED2C;
extern float lbl_8059ED34;
extern unsigned short lbl_8059ED38;
extern const float lbl_805A39E8;
extern const float lbl_805A39F8;
extern const float lbl_805A3A04;

typedef struct {
    char pad0[0xa8];
    float a8;
    float ac;
    char pad1[0x3f4];
    float x;
    float y;
    char pad2[0xc];
    float b8;
    float bc;
    float c0;
    float c4;
    unsigned short c8;
    char pad3[0x42];
    float threshold;
} Obj;

void fn_802258F4(Obj *p)
{
    float len = (float)fn_80400D94(p->x * p->x + p->y * p->y);

    if (lbl_805A39E8 == len || len >= lbl_805A3A04)
        return;
    {
        float nx, ny, factor, u, v, len2, oldy, oldx, sy, sx, newx, newy, dx, dy;
        nx = p->x / len;
        ny = p->y / len;
        if (len > lbl_805A39F8)
            len = lbl_805A3A04 - len;
        len *= len * lbl_8059ED2C;
        u = p->b8 + len * ((p->a8 * nx + p->ac * ny) - p->b8);
        v = p->bc + len * ((p->ac * nx - p->a8 * ny) - p->bc);
        len2 = (float)fn_80400D94(u * u + v * v);
        if (lbl_805A39E8 != len2) {
            sx = u / len2;
            sy = v / len2;
            p->b8 = sx;
            p->bc = sy;
            oldx = p->c0;
            newx = oldx + lbl_8059ED34 * (sx - oldx);
            p->c0 = newx;
            dx = sx - newx;
            oldy = p->c4;
            newy = oldy + lbl_8059ED34 * (sy - oldy);
            p->c4 = newy;
            dy = sy - newy;
            if (dx * dx + dy * dy <= p->threshold) {
                if (p->c8 != 0)
                    p->c8--;
            } else {
                p->c8 = lbl_8059ED38;
            }
        }
    }
}
