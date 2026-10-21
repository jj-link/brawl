#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

struct MuMsgEntry
{
    u8 pad[0x14];
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    u8 rest[0x48 - 0x18];
};

class MuMsg
{
public:
    u8 pad[0xc];
    MuMsgEntry *entries;

    void setFontColor(u32 index, u8 c0, u8 c1, u8 c2, u8 c3);
};

void MuMsg::setFontColor(u32 index, u8 c0, u8 c1, u8 c2, u8 c3)
{
    MuMsgEntry *e = &entries[index];
    e->color0 = c0;
    e->color1 = c1;
    e->color2 = c2;
    e->color3 = c3;
}
