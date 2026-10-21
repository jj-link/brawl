#pragma force_active on
typedef struct Inner {
    int f00, f04, f08, f0c, f10, f14, f18;
    int f1c;
    int f20, f24, f28;
} Inner;
typedef struct Outer {
    char pad[0x2c];
    Inner *f2c;
} Outer;
static inline unsigned int inner_size(const Inner *inner)
{
    return (unsigned int)inner->f1c;
}
extern int fn_80392344(void *, Outer *, void *, int, int, int);
int fn_80391180(void *p0, Outer *p1, void *p2, unsigned int p3, int p4, int p5)
{
    int remaining;
    int base;
    Inner *inner = p1->f2c;
    if (inner_size(inner) <= p3) {
        return -1003;
    }
    remaining = inner->f1c - (int)p3;
    base = inner->f28;
    p3 = base + (int)p3;
    if (p4 > remaining) {
        p4 = remaining;
    }
    return fn_80392344(p0, p1, p2, (int)p3, p4, p5);
}
