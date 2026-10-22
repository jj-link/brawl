#pragma force_active on
extern "C" void fn_8003F074(float *p, float x, float y, float z)
{
    p[3] = p[3] + ((p[2] * z) + ((p[0] * x) + (p[1] * y)));
    p[7] = p[7] + ((p[6] * z) + ((p[4] * x) + (p[5] * y)));
    p[11] = p[11] + ((p[10] * z) + ((p[8] * x) + (p[9] * y)));
}
