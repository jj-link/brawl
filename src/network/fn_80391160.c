#pragma force_active on
typedef struct {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    void *f2c;
} Outer;

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
} Inner;

extern int fn_80392344(void *, Outer *, void *, int, int, int);

int fn_80391160(void *p0, Outer *p1, void *p2, int p3, int p4) {
    Inner *r9 = p1->f2c;
    return fn_80392344(p0, p1, p2, r9->f28 + p3, r9->f1c - p3, p4);
}
