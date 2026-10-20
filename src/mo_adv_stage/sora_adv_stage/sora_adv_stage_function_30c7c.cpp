#pragma force_active on
struct Bits
{
    unsigned int first : 5;
    unsigned int value : 5;
    unsigned int rest : 22;
};

extern "C" void fn_40_30C7C(unsigned int* ptr, unsigned int value)
{
    ((Bits*)&ptr[2])->value = value;
}
