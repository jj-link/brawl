#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_48_B048(const Object* object)
{
    return (object->flags >> 10) & 1;
}
