#pragma force_active on
typedef unsigned char u8;

struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

extern "C" void setSubColor__soColorBlendModuleImplFQ17GXColorUc(
    void* self, GXColor color, u8 enabled)
{
    u8* bytes = static_cast<u8*>(self);
    bytes[0x14a] = color.r;
    bytes[0x14b] = color.g;
    bytes[0x14c] = color.b;
    bytes[0x14d] = color.a;
    bytes[0x14f] = enabled;
}
