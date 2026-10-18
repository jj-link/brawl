#pragma force_active on
struct FtVec3 {
    float x, y, z;
};

extern "C" void fn_92_D29C(FtVec3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
