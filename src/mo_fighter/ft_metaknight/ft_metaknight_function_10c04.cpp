#pragma force_active on
struct MetaKnightFlags {
    unsigned char padding[0xA4];
    unsigned char : 1;
    unsigned char flag : 1;
    unsigned char : 6;
};

extern "C" void fn_111_10C04(MetaKnightFlags* object, unsigned int value)
{
    object->flag = value;
}
