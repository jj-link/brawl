#pragma force_active on
struct VectorFields {
    char padding[0x10];
    float x;
    float y;
    float z;
};

extern "C" void fn_46_6D38(VectorFields* object, float x, float y, float z)
{
    object->x = x;
    object->y = y;
    object->z = z;
}
