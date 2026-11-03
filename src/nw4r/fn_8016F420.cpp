#include <revolution/MTX/mtx.h>
#pragma force_active on

extern const float lbl_805A2D60;
extern const float lbl_805A2D64;

extern "C" void fn_801ED008(const Vec*, Vec*);
extern "C" void fn_801ED0B0(const Vec*, const Vec*, Vec*);

extern "C" void fn_8016F420(const Mtx in, Mtx out) {
    Vec a, b, c;
    a.x = in[0][0];
    a.y = in[1][0];
    a.z = in[2][0];
    if (lbl_805A2D60 != a.x || lbl_805A2D60 != a.y || lbl_805A2D60 != a.z)
        fn_801ED008(&a, &a);
    else
        a.x = lbl_805A2D64;

    b.x = in[0][1];
    b.y = in[1][1];
    b.z = in[2][1];
    if (lbl_805A2D60 != b.x || lbl_805A2D60 != b.y || lbl_805A2D60 != b.z)
        fn_801ED008(&b, &b);
    else
        b.y = lbl_805A2D64;

    fn_801ED0B0(&a, &b, &c);
    fn_801ED0B0(&c, &a, &b);
    out[0][0] = a.x;
    out[1][0] = a.y;
    out[2][0] = a.z;
    out[0][1] = b.x;
    out[1][1] = b.y;
    out[2][1] = b.z;
    out[0][2] = c.x;
    out[1][2] = c.y;
    out[2][2] = c.z;
    out[0][3] = lbl_805A2D60;
    out[1][3] = lbl_805A2D60;
    out[2][3] = lbl_805A2D60;
}
