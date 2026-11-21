#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3D38;
extern const float lbl_805A3D3C;
extern const float lbl_805A3D40;
extern const float lbl_805A3D44;
extern const int lbl_8040F880[4];

double __frsqrte(double);

void fn_802856E4(float *out, float (* __restrict m)[4])
{
    union {
        unsigned int i;
        float fl;
    } inf0, inf1;
    __declspec(align(16)) float result[4];
    int perm[3];
    float f, inv, w, s, x, y;
    const int *table;
    float a, b, c;
    float *mj;
    int ii;
    int pp;
    float *mp;
    int jj;
    float *mi;
    int i, p, j;

    f = m[2][2] + (m[0][0] + m[1][1]);
    if (f > lbl_805A3D40) {
        x = lbl_805A3D3C + f;
        if (x <= lbl_805A3D40) {
            inf0.i = 0x7F800000;
            inv = inf0.fl;
        } else {
            double d = __frsqrte(x);
            float r = (float)d;
            inv = (lbl_805A3D38 * r) *
                  (lbl_805A3D44 - r * (x * r));
        }
        w = lbl_805A3D3C / inv;
        s = lbl_805A3D38 / w;
        a = m[1][2] - m[2][1];
        b = m[2][0] - m[0][2];
        c = m[0][1] - m[1][0];
        result[0] = s * a;
        result[1] = s * b;
        result[2] = s * c;
        result[3] = lbl_805A3D38 * w;
    } else {
        table = lbl_8040F880;
        perm[0] = *table++;
        perm[1] = *table++;
        perm[2] = *table++;
        i = 0;
        if (m[1][1] > m[0][0])
            i = 1;
        if (m[2][2] > m[i][i])
            i = 2;
        ii = i * 4;
        p = *(int *)((char *)perm + ii);
        pp = p * 4;
        j = *(int *)((char *)perm + pp);
        jj = j * 4;
        mi = m[i]; mp = m[p]; mj = m[j];
        y = lbl_805A3D3C + (*(float *)((char *)mi + ii) - (*(float *)((char *)mp + pp) + *(float *)((char *)mj + jj)));
        if (y <= lbl_805A3D40) {
            inf1.i = 0x7F800000;
            inv = inf1.fl;
        } else {
            float r = (float)__frsqrte(y);
            inv = (lbl_805A3D38 * r) *
                  (lbl_805A3D44 - r * (y * r));
        }
        w = lbl_805A3D3C / inv;
        s = lbl_805A3D38 / w;
        *(float *)((char *)result + ii) = lbl_805A3D38 * w;
        result[3] = s * (*(float *)((char *)mp + jj) - *(float *)((char *)mj + pp));
        *(float *)((char *)result + pp) = s * (*(float *)((char *)mi + pp) + *(float *)((char *)mp + ii));
        *(float *)((char *)result + jj) = s * (*(float *)((char *)mi + jj) + *(float *)((char *)mj + ii));
    }

    out[0] = result[0];
    out[1] = result[1];
    out[2] = result[2];
    out[3] = result[3];
}
