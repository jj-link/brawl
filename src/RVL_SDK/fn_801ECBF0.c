#pragma force_active on
extern double fn_80400AB8(double);
extern const float lbl_805A3758;
extern const float lbl_805A375C;
extern const float lbl_805A3760;
extern const float lbl_805A376C;
extern const float lbl_805A3770;

void fn_801ECBF0(float m[3][4], float fov, float aspect,
                 float scaleS, float scaleT, float transS, float transT)
{
    float cot = lbl_805A3758 /
        (float)fn_80400AB8(lbl_805A3770 * (lbl_805A3760 * fov));

    m[0][0] = scaleS * (cot / aspect);
    m[0][1] = lbl_805A375C;
    m[0][2] = -transS;
    m[0][3] = lbl_805A375C;
    m[1][0] = lbl_805A375C;
    m[1][1] = cot * scaleT;
    m[1][2] = -transT;
    m[1][3] = lbl_805A375C;
    m[2][0] = lbl_805A375C;
    m[2][1] = lbl_805A375C;
    m[2][2] = lbl_805A376C;
    m[2][3] = lbl_805A375C;
}
