#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3E70;

extern "C" void fn_80297AD4(float *out, float *m, float *v)
{
    float a, b, c;
    float y = v[1];
    float x = v[0];
    float z = v[2];

    a = (z * m[8]) + ((x * m[0]) + (y * m[4]));
    b = (z * m[9]) + ((x * m[1]) + (y * m[5]));
    c = (z * m[10]) + ((x * m[2]) + (y * m[6]));

    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = lbl_805A3E70;
}