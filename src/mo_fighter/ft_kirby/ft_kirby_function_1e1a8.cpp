#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 6;
    unsigned int field : 6;
    unsigned int : 20;
};

extern "C" void fn_96_1E1A8(Data* object, unsigned int value)
{
    object->field = value;
}
