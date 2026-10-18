#pragma force_active on
struct IceClimberVec3 {
    float x, y, z;
};

extern "C" void fn_105_C1C0(IceClimberVec3 *vector, float x, float y, float z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
