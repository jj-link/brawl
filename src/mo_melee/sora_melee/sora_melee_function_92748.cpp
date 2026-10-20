#pragma force_active on
struct Fields
{
    unsigned int reserved : 10;
    unsigned int value : 10;
    unsigned int rest : 12;
};

extern "C" void fn_27_92748(Fields *p, unsigned int value)
{
    Fields *field = (Fields *)((char *)p + 8);
    field->value = value;
}
