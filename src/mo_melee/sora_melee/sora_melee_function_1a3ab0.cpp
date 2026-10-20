#pragma force_active on
struct Bits {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 12;
};

extern "C" void fn_27_1A3AB0(unsigned int* p, unsigned int v)
{
    Bits* s = (Bits*)&p[2];
    s->b = v;
}
