#pragma force_active on
struct ToonLinkFlags
{
    unsigned char padding[0xA4];
    unsigned char unused : 1;
    unsigned char flag : 1;
    unsigned char remaining : 6;
};

extern "C" bool fn_121_144D8(const ToonLinkFlags* object)
{
    return object->flag;
}
