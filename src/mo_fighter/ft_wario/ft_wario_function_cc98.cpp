#pragma force_active on
struct FtVec3f {
    float x, y, z;
};

extern "C" void fn_110_CC98(FtVec3f* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
