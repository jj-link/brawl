#pragma force_active on
struct Field
{
    unsigned int value : 7;
    unsigned int reserved : 25;
};

extern "C" void fn_27_D000C(void *self, unsigned int value)
{
    ((Field *)((char *)self + 8))->value = value;
}
