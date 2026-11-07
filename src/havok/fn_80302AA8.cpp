#pragma force_active on
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
struct State { u16 a[4]; s8 x; u8 y; };
extern "C" void fn_80302AA8(State* s, int* in) {
    if (in[0]) {
        s->a[0] = (1 - ((s->a[0] >> 7) & 1)) << 4;
        if (s->x > 1) {
            s->a[0] = 16;
            s->a[1] = 0;
            if (s->x == 3) {
                s->x = 2;
                s->a[2] = s->a[3];
            }
        }
    }
    if (in[1]) {
        s->a[s->x] = (1 - ((s->a[s->x] >> 7) & 1)) << 4;
        if ((s8)s->y > 1) {
            s->a[s->x] = 16;
            s->a[s->x + 1] = 0;
            if ((int)s->y == 3) s->y = 2;
        }
    }
}