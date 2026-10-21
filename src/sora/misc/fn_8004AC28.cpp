#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct ipPadStatus {
    u16 unk0;
    u8 unk2;
    u8 unk3;
};

class ipSwitch {
public:
    int getPadStatus(long index, ipPadStatus& out);
};

int ipSwitch::getPadStatus(long index, ipPadStatus& out) {
    u8* entry = (u8*)this + index * 4;
    out.unk0 = *(u16*)(entry + 0x8);
    out.unk2 = entry[0xA];
    out.unk3 = entry[0xB];
    return 1;
}
