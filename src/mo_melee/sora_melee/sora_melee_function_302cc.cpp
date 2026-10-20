#pragma force_active on
struct Src {
    char pad[0x20];
    float x;
    float y;
    float z;
};

extern "C" void fn_27_302CC(Src* src, void* unused, float* outX, float* outY, float* outZ)
{
    float x = src->x;
    float y = src->y;
    *outX = x;
    float z = src->z;
    *outY = y;
    *outZ = z;
}
