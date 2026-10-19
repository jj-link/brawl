#pragma force_active on
struct KirbyData
{
    unsigned int padding[2];
    unsigned int value : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_96_1E250(KirbyData* object, unsigned int value)
{
    object->value = value;
}
