#pragma force_active on
typedef struct { float x, y, z; } Vec3;
inline void swap(Vec3 &a, Vec3 &b) {
    Vec3 t = a;
    a = b;
    b = t;
}
extern "C" void fn_40_34F90(Vec3 **a, Vec3 **b, Vec3 **c)
{
    Vec3 *bp;
    Vec3 *cp;
    Vec3 *ap;
    ap = *a;
    cp = *c;
    int first = !(cp->y < ap->y);
    bp = *b;
    int second = !(bp->y < cp->y);
    if (first != 0) {
        if (second != 0) return;
    }
    if (first == 0 && second == 0) {
        swap(**a, **b);
        return;
    }
    int lt = bp->y < ap->y;
    if (lt != 0) {
        swap(**a, **b);
    }
    if (first != 0) {
        swap(**b, **c);
    } else {
        swap(**a, **c);
    }
}