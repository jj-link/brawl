#pragma force_active on
#include <nw4r/math/math_arithmetic.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
extern "C" {
extern void* memset(void*, int, unsigned long);
extern void fn_800A8DB4(void*, void*, void*, int);
extern float lbl_805A20C4;
extern float lbl_805A208C;
union FloatInt { float f; unsigned int i; };
struct Pair { FloatInt x, y; };
struct Result { unsigned char a; Pair p1, p2; };
struct Local {
    unsigned char r_a; char pad1[3];
    unsigned int r_x1, r_y1, r_x2, r_y2;
    unsigned char r_a2; char pad1b[3];
    FloatInt t_x1, t_y1, t_x2, t_y2;
    unsigned char acc_a; char pad2[3];
    Pair p1, p2;
};
inline float clamp(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
void fn_800A8C18(void* arg0, int arg1) {
    gfPadStatus padStatus;
    Local loc;
    memset(&loc.acc_a, 0, 0x14);
    for (int i = 0; i < 8; i++) {
        g_gfPadSystem->getSysPadStatus(i, &padStatus);
        if (padStatus.m_error != 0) continue;
        fn_800A8DB4(&loc.r_a, arg0, &padStatus, arg1);
        loc.r_a2 = loc.r_a;
        loc.t_x1.i = loc.r_x1;
        loc.t_y1.i = loc.r_y1;
        loc.t_x2.i = loc.r_x2;
        loc.t_y2.i = loc.r_y2;
        loc.acc_a |= loc.r_a;
        loc.p1.x.f += loc.t_x1.f;
        loc.p1.y.f += loc.t_y1.f;
        loc.p2.x.f += loc.t_x2.f;
        loc.p2.y.f += loc.t_y2.f;
    }
    loc.p1.x.f = clamp(loc.p1.x.f, lbl_805A20C4, lbl_805A208C);
    loc.p1.y.f = clamp(loc.p1.y.f, lbl_805A20C4, lbl_805A208C);
    loc.p2.x.f = clamp(loc.p2.x.f, lbl_805A20C4, lbl_805A208C);
    loc.p2.y.f = clamp(loc.p2.y.f, lbl_805A20C4, lbl_805A208C);
    *(Result*)((char*)arg0 + 0x14) = *(Result*)&loc.acc_a;
}
}