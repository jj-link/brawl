#pragma force_active on
struct Fn47_4E08Object
{
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_47_4E08(const Fn47_4E08Object* object)
{
    return (object->flags >> 25) & 1;
}
