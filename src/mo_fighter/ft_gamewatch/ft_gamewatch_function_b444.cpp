#pragma force_active on
struct Float3 {
    float x, y, z;
};

extern "C" void fn_107_B444(Float3 *vector, float x, float y, float z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
