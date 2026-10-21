#pragma force_active on
typedef union Vec4 {
    struct {
        float x, y, z, w;
    } f;
    double d[2];
} Vec4 __attribute__((aligned(16)));

void fn_80289708(float *dst, const Vec4 *src)
{
    Vec4 a = src[0];
    Vec4 b = src[1];
    Vec4 c = src[2];
    Vec4 d = src[3];

    dst[0] = a.f.x;
    dst[1] = a.f.y;
    dst[2] = a.f.z;
    dst[3] = a.f.w;
    dst[4] = b.f.x;
    dst[5] = b.f.y;
    dst[6] = b.f.z;
    dst[7] = b.f.w;
    dst[8] = c.f.x;
    dst[9] = c.f.y;
    dst[10] = c.f.z;
    dst[11] = c.f.w;
    dst[12] = d.f.x;
    dst[13] = d.f.y;
    dst[14] = d.f.z;
    dst[15] = d.f.w;
}
