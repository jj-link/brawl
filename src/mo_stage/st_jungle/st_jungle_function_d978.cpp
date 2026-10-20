#pragma force_active on
extern "C" void fn_51_D978(unsigned int *obj, unsigned int v)
{
    struct Bits {
        unsigned int a : 3;
        unsigned int f : 3;
        unsigned int b : 26;
    };
    ((Bits *)&obj[2])->f = v;
}
