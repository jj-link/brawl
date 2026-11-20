#pragma force_active on
#pragma fp_contract off

extern double fn_80400D94(double);
extern float lbl_8059ED40;
extern float lbl_8059ED4C;
extern const float lbl_805A39E8;
extern const float lbl_805A39F8;
extern const float lbl_805A3A04;

typedef struct {
    float x;
    float y;
} Vec2;

typedef struct {
    float x;
    float y;
    signed char flag;
    char pad[3];
} Elem;

int fn_802263D4(void *arg0)
{
    float best = lbl_805A3A04;
    float scale;
    char *base;
    float threshold;
    Elem *outer_end;
    Elem *inner_end;
    Elem *outer = (Elem *)((char *)arg0 + 0xC4);
    Elem *inner;
    Elem *best_first;
    Elem *best_second;

    threshold = lbl_805A39E8;
    scale = lbl_805A39F8;
    base = (char *)arg0;
    outer_end = (Elem *)(base + 0xE8);

    do {
        if (outer->flag == 0) {
            inner = outer + 1;
            inner_end = (Elem *)(base + 0xE8);

            do {
                if (inner->flag == 0) {
                    float dx = inner->x - outer->x;
                    float dy = inner->y - outer->y;

                    {
                        float inverse;
                        Vec2 n;
                        float speed;

                        inverse = scale / (float)fn_80400D94((dx * dx) + (dy * dy));
                        n.x = dx * inverse;
                        n.y = dy * inverse;
                        speed = (inverse *= (*(float *)(base + 0x510)));

                        if ((!(speed <= (*(float *)(base + 0x514)))) &&
                            (!(speed >= lbl_8059ED40))) {
                            float t = speed - (*(float *)(base + 0x49C));

                            if (t < threshold)
                                t *= (*(float *)(base + 0x508));
                            else
                                t *= (*(float *)(base + 0x504));

                            if (!(t >= scale)) {
                                float d = (*(float *)(base + 0x494)) * n.x +
                                          (*(float *)(base + 0x498)) * n.y;
                                int s;

                                if (d < threshold) {
                                    d = -d;
                                    s = 1;
                                } else {
                                    s = 0;
                                }

                                if (!(d <= lbl_8059ED4C)) {
                                    t += (scale - d) / (scale - lbl_8059ED4C);
                                    if (t < best) {
                                        best = t;
                                        if (s != 0) {
                                            best_first = inner;
                                            best_second = outer;
                                        } else {
                                            best_first = outer;
                                            best_second = inner;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                inner++;
            } while (inner <= inner_end);
        }
        outer++;
    } while (outer < outer_end);

    if (lbl_805A3A04 == best)
        return 0;

    *(Elem *)(base + 0xF4) = *best_first;
    *(Elem *)(base + 0x100) = *best_second;
    return 2;
}
