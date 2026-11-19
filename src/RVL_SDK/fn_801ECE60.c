#pragma force_active on
extern double fn_80400AB8(double);
extern const float lbl_805A3778;
extern const float lbl_805A3780;
extern const float lbl_805A3784;
extern const float lbl_805A3788;
extern const float lbl_805A378C;

void fn_801ECE60(float m[4][4], float fov, float aspect, float n, float f)
{
    float rad, cot;
    float invrange;
    rad = lbl_805A378C * (lbl_805A3788 * fov);
    cot = lbl_805A3778 / (float)fn_80400AB8(rad);
    m[0][0] = cot / aspect;
    m[0][1] = lbl_805A3780;
    m[0][2] = lbl_805A3780;
    m[0][3] = lbl_805A3780;
    m[1][0] = lbl_805A3780;
    m[1][1] = cot;
    m[1][2] = lbl_805A3780;
    m[1][3] = lbl_805A3780;
    invrange = lbl_805A3778 / (f - n);
    m[2][0] = lbl_805A3780;
    m[2][1] = lbl_805A3780;
    m[2][2] = -n * invrange;
    m[2][3] = invrange * -(f * n);
    m[3][0] = lbl_805A3780;
    m[3][1] = lbl_805A3780;
    m[3][2] = lbl_805A3784;
    m[3][3] = lbl_805A3780;
}