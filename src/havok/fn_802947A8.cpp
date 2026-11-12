#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A3E10;

struct hkVector4 {
    float x, y, z, w;
    inline void set(float a, float b, float c, float d) {
        x = a; y = b; z = c; w = d;
    }
};

extern "C" void fn_802947A8(hkVector4* dst, const hkVector4* a, const hkVector4* b)
{
    const float nx = a->y * b->z - a->z * b->y;
    const float ny = a->z * b->x - a->x * b->z;
    const float nz = a->x * b->y - a->y * b->x;
    dst->set(nx, ny, nz, lbl_805A3E10);
}
