#pragma force_active on
typedef unsigned char u8;

struct Fn27Entry {
    u8 pad[0x14];
};

struct Fn27Base {
    u8 header[0xC];
};

extern "C" {
Fn27Entry* fn_27_19C8BC(Fn27Base* base, int index)
{
    return (Fn27Entry*)((u8*)base + index * 0x14 + 0xC);
}
}
