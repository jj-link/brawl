/* fn_801EBD2C: best match found, 92.3% (the copy block at the 0x801EC0xx region still differs:
 * the original uses lis r29 / lbzu r30 as the base for lbl_804DE6C0 and a different constant register). */
#pragma force_active on
typedef unsigned char u8;
extern void fn_801EA4E4(int, u8 *, int);
extern void fn_801EA098(int);
extern int fn_801E9C9C(void);
extern void fn_801EAAB4(int);
extern void fn_801EBA48(void *);
extern u8 lbl_8059EA48, lbl_8059EA49, lbl_8059EA4A, lbl_8059EA4B, lbl_8059EA4C, lbl_8059EA4D, lbl_8059EA4E, lbl_8059EA4F, lbl_8059EA50, lbl_8059EA51, lbl_8059EA52;
extern int lbl_805A0858, lbl_805A085C, lbl_805A0868;
extern u8 lbl_804DE6C0[32];
extern char lbl_804754A8[];

void fn_801EBD2C(void) {
    u8 a[2], b[2], c[2], d[3], e[2], f[3], g[3], h[5], i[27], j[2], k[2];
    a[0] = 0x6a; a[1] = 1;
    fn_801EA4E4(0xe0, a, 2); fn_801EA098(2);
    b[1] = 1; b[0] = 0x65;
    fn_801EA4E4(0xe0, b, 2); fn_801EA098(2);
    fn_801EAAB4((u8)fn_801E9C9C());
    c[0] = 0; c[1] = 0;
    fn_801EA4E4(0xe0, c, 2); fn_801EA098(2);
    d[0] = 0x71; d[1] = 0x8e; d[2] = 0x8e;
    fn_801EA4E4(0xe0, d, 3); fn_801EA098(2);
    e[0] = 2; e[1] = 7;
    fn_801EA4E4(0xe0, e, 2); fn_801EA098(2);
    lbl_8059EA48 = 0; lbl_8059EA49 = 0; lbl_8059EA4A = 0;
    f[0] = 5; f[1] = 0; f[2] = 0;
    fn_801EA4E4(0xe0, f, 3); fn_801EA098(2);
    if (lbl_8059EA4B || lbl_8059EA4C || lbl_8059EA4D || lbl_8059EA4E) {
        lbl_8059EA4B = 0; lbl_8059EA4C = 0; lbl_8059EA4D = 0; lbl_8059EA4E = 0;
        lbl_805A0858 |= 2;
    }
    g[0] = 8; g[1] = ((lbl_8059EA4C << 4) & 0xf0) | (lbl_8059EA4B & 15);
    g[2] = ((lbl_8059EA4E << 3) & 0x38) | (lbl_8059EA4D & 7);
    fn_801EA4E4(0xe0, g, 3); fn_801EA098(2);
    if (lbl_8059EA4F || lbl_8059EA50 || lbl_8059EA51 || lbl_8059EA52) {
        lbl_8059EA4F = 0; lbl_8059EA50 = 0; lbl_8059EA51 = 0; lbl_8059EA52 = 0;
        lbl_805A0858 |= 4;
    }
    h[0] = 0x7a; h[1] = lbl_8059EA4F & 0x7f; h[2] = lbl_8059EA50 & 0x7f;
    h[3] = lbl_8059EA51 & 0x7f; h[4] = lbl_8059EA52 & 0x7f;
    fn_801EA4E4(0xe0, h, 5); fn_801EA098(2);
    i[0] = 0x40;
    {
        int n;
#pragma unroll
        for (n = 1; n < 27; n++) {
            i[n] = lbl_804DE6C0[n - 1];
        }
    }
    fn_801EA4E4(0xe0, i, 27); fn_801EA098(2);
    if (lbl_805A085C) { lbl_805A085C = 0; lbl_805A0858 |= 0x40; }
    if (lbl_805A0868 == 3) {
        j[0] = 10; j[1] = (lbl_805A085C << 1) | 1;
        fn_801EA4E4(0xe0, j, 2); fn_801EA098(2);
    } else {
        j[0] = 10; j[1] = 0;
        fn_801EA4E4(0xe0, j, 2); fn_801EA098(2);
    }
    k[0] = 3; k[1] = 1;
    fn_801EA4E4(0xe0, k, 2); fn_801EA098(2);
    fn_801EBA48(lbl_804754A8 + 0x154);
}
