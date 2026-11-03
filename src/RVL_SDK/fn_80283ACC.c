#pragma force_active on
void fn_80283ACC(float *m)
{
    float t0 = m[4];
    float t1 = m[8];
    float t2 = m[12];
    float t3 = m[9];
    float t4 = m[13];
    float t5 = m[14];

    m[4] = m[1];
    m[1] = t0;
    m[8] = m[2];
    m[2] = t1;
    m[12] = m[3];
    m[3] = t2;
    m[9] = m[6];
    m[6] = t3;
    m[13] = m[7];
    m[7] = t4;
    m[14] = m[11];
    m[11] = t5;
}
