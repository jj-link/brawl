#pragma force_active on
extern double fn_80400D94(double);
extern const float lbl_805A37E8, lbl_805A3800, lbl_805A3818;
void fn_801F22F4(void *p, float x, float y, float z) {
    float a = -x, b = -y, c = lbl_805A3800 + -z;
    float d = c*c + (a*a + b*b);
    if (lbl_805A37E8 != d) d = lbl_805A3800 / (float)fn_80400D94(d);
    *(float *)((char *)p + 0x34) = a*d;
    *(float *)((char *)p + 0x38) = b*d;
    *(float *)((char *)p + 0x3c) = c*d;
    *(float *)((char *)p + 0x28) = lbl_805A3818*x;
    *(float *)((char *)p + 0x2c) = lbl_805A3818*y;
    *(float *)((char *)p + 0x30) = lbl_805A3818*z;
}