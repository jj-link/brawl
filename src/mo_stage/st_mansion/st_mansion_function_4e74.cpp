#pragma force_active on
struct Bits {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" void fn_47_4E74(Bits *obj, unsigned int val)
{
    obj->b = val;
}
