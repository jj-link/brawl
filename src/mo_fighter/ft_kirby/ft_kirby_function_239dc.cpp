#pragma force_active on
struct KirbyFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

struct KirbyObject {
    unsigned char padding[0xA4];
    KirbyFlags flags;
};

extern "C" void fn_96_239DC(KirbyObject* object, char selected)
{
    object->flags.selected = selected;
}