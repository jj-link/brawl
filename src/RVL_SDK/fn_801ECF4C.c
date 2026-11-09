#pragma force_active on
extern const float lbl_805A3778;
extern const float lbl_805A377C;
extern const float lbl_805A3780;
extern const float lbl_805A3784;

typedef float Mtx44[4][4];

void fn_801ECF4C(Mtx44 m, float t, float b, float l, float r, float n, float f)
{
    float tmp;

    tmp = lbl_805A3778 / (r - l);
    m[0][0] = lbl_805A377C * tmp;
    m[0][1] = lbl_805A3780;
    m[0][2] = lbl_805A3780;
    m[0][3] = tmp * -(r + l);

    tmp = lbl_805A3778 / (t - b);
    m[1][0] = lbl_805A3780;
    m[1][1] = lbl_805A377C * tmp;
    m[1][2] = lbl_805A3780;
    m[1][3] = tmp * -(t + b);

    tmp = lbl_805A3778 / (f - n);
    m[2][0] = lbl_805A3780;
    m[2][1] = lbl_805A3780;
    m[2][2] = lbl_805A3784 * tmp;
    m[2][3] = -f * tmp;

    m[3][0] = lbl_805A3780;
    m[3][1] = lbl_805A3780;
    m[3][2] = lbl_805A3780;
    m[3][3] = lbl_805A3778;
}
