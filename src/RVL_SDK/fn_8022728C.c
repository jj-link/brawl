#pragma force_active on
extern double fn_80400D94(double);
extern float lbl_805A39E8;
extern float lbl_805A39F8;

void fn_8022728C(float *out, int x, int y, int min, int max)
{
    float a, b, len;
    if (x < 0) {
        int v = -x;
        if (v <= min)
            out[0] = lbl_805A39E8;
        else if (v >= max)
            out[0] = lbl_805A39F8;
        else
            out[0] = (float)-(x + min) / (float)(max - min);
        out[0] = -out[0];
    } else if (x <= min)
        out[0] = lbl_805A39E8;
    else if (x >= max)
        out[0] = lbl_805A39F8;
    else
        out[0] = (float)(x - min) / (float)(max - min);
    if (y < 0) {
        int v = -y;
        if (v <= min)
            out[1] = lbl_805A39E8;
        else if (v >= max)
            out[1] = lbl_805A39F8;
        else
            out[1] = (float)-(y + min) / (float)(max - min);
        out[1] = -out[1];
    } else if (y <= min)
        out[1] = lbl_805A39E8;
    else if (y >= max)
        out[1] = lbl_805A39F8;
    else
        out[1] = (float)(y - min) / (float)(max - min);
    a = out[0];
    b = out[1];
    if (a * a + b * b > lbl_805A39F8) {
        len = (float)fn_80400D94(a * a + b * b);
        out[0] = out[0] / len;
        out[1] = out[1] / len;
    }
}
