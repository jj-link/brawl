#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3D88;

void fn_80287A64(float *out, float *m, float *v)
{
    float a, b, c;
    float y = v[1];
    float z = v[2];
    float x = v[0];

    a = (z * m[2]) + ((x * m[0]) + (y * m[1]));
    b = (z * m[6]) + ((x * m[4]) + (y * m[5]));
    c = (z * m[10]) + ((x * m[8]) + (y * m[9]));

    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = lbl_805A3D88;
}
