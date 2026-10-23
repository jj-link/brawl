#pragma force_active on
extern const float lbl_805A3778;
extern const float lbl_805A377C;
extern const float lbl_805A3780;
extern const float lbl_805A3784;

void fn_801ECDC4(float m[4][4], float t, float b, float l,
                 float r, float n, float f)
{
    float invRL, invTB, invFN, tmp;

    invRL = lbl_805A3778 / (r - l);
    tmp = lbl_805A377C * n;
    m[0][0] = tmp * invRL;
    m[0][1] = lbl_805A3780;
    m[0][2] = invRL * (r + l);
    m[0][3] = lbl_805A3780;

    invTB = lbl_805A3778 / (t - b);
    m[1][0] = lbl_805A3780;
    m[1][1] = tmp * invTB;
    m[1][2] = invTB * (t + b);
    m[1][3] = lbl_805A3780;

    invFN = lbl_805A3778 / (f - n);
    m[2][0] = lbl_805A3780;
    m[2][1] = lbl_805A3780;
    m[2][2] = -n * invFN;
    m[2][3] = invFN * -(f * n);

    m[3][0] = lbl_805A3780;
    m[3][1] = lbl_805A3780;
    m[3][2] = lbl_805A3784;
    m[3][3] = lbl_805A3780;
}
