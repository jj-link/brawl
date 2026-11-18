#pragma force_active on
extern double fn_80400D94(float);
extern const float lbl_805A39E8;
extern const float lbl_805A39F8;
extern const float lbl_805A3A04;
extern float lbl_8059ED2C;
typedef struct { char pad0[0x54]; float x, y; char pad1[0x448]; float a, b, c; } Object;
void fn_80225A88(Object *p) {
    float nx, oy, ox, t, t2;
    float sum = p->a * p->a + p->b * p->b;
    float x = (float)fn_80400D94(sum);
    float y = -p->c;
    float len = (float)fn_80400D94(sum + y * y);
    if (lbl_805A39E8 == len || len >= lbl_805A3A04) return;
    nx = x / len;
    y /= len;
    if (len > lbl_805A39F8) len = lbl_805A3A04 - len;
    ox = p->x;
    t = len * lbl_8059ED2C;
    oy = p->y;
    len *= t;
    nx -= ox;
    t2 = len;
    t2 *= nx;
    x = ox + t2;
    y = oy + len * (y - oy);
    len = (float)fn_80400D94(x * x + y * y);
    if (lbl_805A39E8 != len) {
        p->x = x / len;
        p->y = y / len;
    }
}
