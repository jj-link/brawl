#pragma force_active on
struct PeachFlags {
    unsigned char padding[0xA4];
    unsigned char unused : 1;
    unsigned char flag : 1;
    unsigned char rest : 6;
};

extern "C" void fn_103_13050(PeachFlags* object, unsigned int value)
{
    object->flag = value;
}
