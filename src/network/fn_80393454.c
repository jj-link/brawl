#pragma force_active on
typedef struct Work {
    unsigned char pad[0x24];
    unsigned char *data;
    unsigned int count;
} Work;

extern Work *fn_803970CC(int);
extern int fn_8039718C(int, Work *, int, int);
extern int fn_80393270(int *, int, int, int, void *, int);
extern void fn_80392738(void *, int);
extern int fn_803928F4(void *, signed char);

int fn_80393454(int a0, int *a1, int a2, int a3, int a4, int a5, int a6)
{
    int total = 0;
    unsigned int count;
    unsigned int i;
    Work *w;
    w = fn_803970CC(a0);
    if (w == 0) {
        return 3;
    }
    w->data = 0;
    for (;;) {
        unsigned char *data;
        int r;
        if (*a1 != 0) {
            return 3;
        }
        w->count = 0;
        if (fn_8039718C(a0, w, a3, total) < 0) {
            return 3;
        }
        count = w->count;
        data = w->data;
        if (count == 0) {
            break;
        }
        if (data == 0) {
            return 3;
        }
        total += count;
        switch (a6) {
        case 0:
        case 1:
            r = fn_80393270(a1, a2, a4, a5, data, count);
            if (r < 0) {
                return 1;
            }
            if (r == 0) {
                return 2;
            }
            break;
        case 2: {
            for (i = 0; i < count; i++) {
                unsigned char buf[16];
                fn_80392738(buf, 3);
                r = fn_80393270(a1, a2, a4, a5, buf, fn_803928F4(buf, data[i]));
                if (r < 0) {
                    return 1;
                }
                if (r == 0) {
                    return 2;
                }
            }
            break;
        }
        }
    }
    return 0;
}
