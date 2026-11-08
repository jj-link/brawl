#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3D88;

void fn_80287974(float *out, const float *m, const float *v)
{
    float w = v[1] - m[13];
    float x = v[0] - m[12];
    float z = v[2] - m[14];
    float a, b, c;

    a = z * m[2] + (x * m[0] + w * m[1]);
    c = z * m[6] + (x * m[4] + w * m[5]);
    b = z * m[10] + (x * m[8] + w * m[9]);

    out[3] = lbl_805A3D88;
    out[1] = c;
    out[2] = b;
    out[0] = a;
}
