#pragma force_active on
#pragma fp_contract on

extern "C" {
void fn_8032D2D4(float* a, float* b, float s) {
    float t0, t2, t3, t6, t7, u, sq;

    t2 = a[2];
    sq = t2 * t2;
    t0 = a[1];
    b[0] = -((s * ((t0 * t0) + sq)) - b[0]);

    t7 = a[0];
    t6 = a[2];
    t7 *= t7;
    t6 = t6 * t6 + t7;
    b[5] = -((s * t6) - b[5]);

    t6 = a[1];
    t7 = a[0];
    t6 *= t6;
    t7 = t7 * t7 + t6;
    b[10] = -((s * t7) - b[10]);

    u = s * a[0];
    t3 = (u * a[1]) + b[1];
    b[1] = t3;
    b[4] = t3;

    u = s * a[1];
    t2 = (u * a[2]) + b[6];
    b[6] = t2;
    b[9] = t2;

    u = s * a[2];
    t0 = (u * a[0]) + b[8];
    b[8] = t0;
    b[2] = t0;
}
}
