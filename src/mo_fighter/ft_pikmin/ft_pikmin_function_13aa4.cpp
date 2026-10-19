#pragma force_active on
struct Fields
{
    unsigned int pad : 10;
    unsigned int value : 5;
};

extern "C" void fn_113_13AA4(void *obj, unsigned int value)
{
    ((Fields *)((char *)obj + 8))->value = value;
}
