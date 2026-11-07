#pragma force_active on
typedef unsigned int u32;
typedef struct { u32 count; u32 w[64]; } Big;
extern int fn_8035F370(u32 *, u32, u32 *, u32, u32 *, u32 *, u32);
extern void fn_8035ED9C(u32 *, u32, u32 *, u32, u32 *, u32 *, u32);
extern void fn_8035F024(u32 *, u32, u32 *, u32, u32 *, u32 *);
extern int fn_8035EC44(u32 *, u32 *, u32 *);
extern int fn_8035EB8C(u32 *, u32);
extern void *memset(void *, int, unsigned long);

int fn_8035FF4C(u32 *a, u32 *b, u32 n, u32 *r, u32 *rn, u32 max) {
    u32 *dst;
    u32 *src;
    u32 h;
    Big A;
    Big B;
    Big C;
    if (n <= 0x20) {
        return fn_8035F370(a, n, b, n, r, rn, max);
    }
    h = n >> 1;
    A.count = 0;
    B.count = 0;
    C.count = 0;
    fn_8035FF4C(a + h, b + h, h, (u32 *)((char *)r + n * sizeof(u32)), rn, max - n);
    fn_8035FF4C(a, b, h, r, rn, max);
    fn_8035ED9C(a + h, h, a, h, A.w, &A.count, 64);
    fn_8035ED9C(b + h, h, b, h, B.w, &B.count, 64);
    memset(&C, 0, sizeof(Big));
    if (A.count > h || B.count > h) {
        fn_8035F370(A.w, A.count, B.w, B.count, C.w + h, &C.count, 64 - h);
    } else {
        if (fn_8035EC44(&A.count, &B.count, rn) == 0) return 0;
        fn_8035EB8C(&A.count, *rn);
        fn_8035EB8C(&B.count, *rn);
        fn_8035FF4C(A.w, B.w, *rn, C.w + h, &C.count, 64 - h);
    }
    C.count += h;
    memset(C.w, 0, h * sizeof(u32));
    dst = C.w;
    src = dst;
    dst += h;
    src += h;
    fn_8035F024(r + n, n, src, C.count - h, dst, &C.count);
    C.count += h;
    fn_8035F024(r, n, src, C.count - h, dst, &C.count);
    C.count += h;
    fn_8035ED9C(r, n * 2, C.w, C.count, r, rn, max);
    while (*rn != 0 && r[*rn - 1] == 0) {
        (*rn)--;
    }
    return 1;
}
