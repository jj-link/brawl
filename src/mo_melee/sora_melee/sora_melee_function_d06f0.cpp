#pragma force_active on
struct Fn27D06F0Object {
    unsigned char pad[8];
    unsigned int bits;
};

extern "C" void fn_27_D06F0(Fn27D06F0Object *obj, unsigned int value)
{
    obj->bits = __rlwimi(obj->bits, value, 11, 14, 20);
}
