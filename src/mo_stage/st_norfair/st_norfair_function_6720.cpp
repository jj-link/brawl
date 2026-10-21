#pragma force_active on
struct NorfairObject {
    unsigned char padding[8];
    unsigned int : 6;
    unsigned int field : 3;
    unsigned int : 23;
};

extern "C" void fn_54_6720(NorfairObject* object, unsigned int value)
{
    object->field = value;
}
