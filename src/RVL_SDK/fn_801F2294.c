#pragma force_active on
typedef struct {
    char pad[0x28];
    float x;
    float y;
    float z;
} FnSrc;

void fn_801F2294(FnSrc* src, float* outX, float* outY, float* outZ) {
    float x, y, z;
    x = src->x;
    y = src->y;
    *outX = x;
    z = src->z;
    *outY = y;
    *outZ = z;
}
