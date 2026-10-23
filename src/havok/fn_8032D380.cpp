#pragma force_active on
#pragma fp_contract on

extern "C" void fn_8032D380(float* v, float* m, float s) {
    float z2 = v[2] * v[2];
    m[0] = s * (v[1] * v[1] + z2) + m[0];

    float x2 = v[0] * v[0];
    m[5] = s * (v[2] * v[2] + x2) + m[5];

    float y2 = v[1] * v[1];
    m[10] = s * (v[0] * v[0] + y2) + m[10];

    float sx = s * v[0];
    float xy = -((sx * v[1]) - m[1]);
    m[1] = xy;
    m[4] = xy;

    float sy = s * v[1];
    float yz = -((sy * v[2]) - m[6]);
    m[6] = yz;
    m[9] = yz;

    float sz = s * v[2];
    float zx = -((sz * v[0]) - m[8]);
    m[8] = zx;
    m[2] = zx;
}
