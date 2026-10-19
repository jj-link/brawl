#pragma force_active on
struct Fn47_40A8Object
{
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" unsigned int fn_47_40A8(const Fn47_40A8Object *object)
{
    return (object->flags >> 25) & 1;
}
