#pragma force_active on
struct Fields {
    unsigned int value : 10;
    unsigned int : 22;
};

extern "C" void fn_27_1A6128(unsigned int *p, unsigned int value)
{
    ((Fields *)((char *)p + 8))->value = value;
}
