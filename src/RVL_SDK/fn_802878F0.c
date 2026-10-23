#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3D88;

void fn_802878F0(float *out, float *m, float *v)
{
    float a, b, c;
    float y = v[1];
    float z = v[2];
    float x = v[0];

    a = m[12] + ((z * m[8]) + ((x * m[0]) + (y * m[4])));
    b = m[13] + ((z * m[9]) + ((x * m[1]) + (y * m[5])));
    c = m[14] + ((z * m[10]) + ((x * m[2]) + (y * m[6])));

    out[3] = lbl_805A3D88;
    out[0] = a;
    out[1] = b;
    out[2] = c;
}
