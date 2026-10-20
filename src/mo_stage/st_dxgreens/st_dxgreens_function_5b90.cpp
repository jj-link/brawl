#pragma force_active on
struct Fn79_5B90Object
{
    unsigned char padding[8];
    unsigned int value;
};

extern "C" void fn_79_5B90(Fn79_5B90Object *object, unsigned int value)
{
    object->value = __rlwimi(object->value, value, 28, 0, 3);
}
