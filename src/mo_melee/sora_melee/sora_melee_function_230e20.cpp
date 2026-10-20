#pragma force_active on
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern "C" {
void fn_27_230E20(char* base, Vec3* out, int idx)
{
    Vec3* src = (Vec3*)(base + idx * 12 + 0x26c);
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
}
}
