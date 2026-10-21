#pragma force_active on
struct Message {
    char pad0[0x9C];
    int unk9C;
    char padA0[0x1D0 - 0xA0];
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int changeMsgBuf(int arg0);
};

int Message::changeMsgBuf(int arg0)
{
    if (arg0 == -1) {
        unk1D0 = unk1D4;
    } else {
        unk1D0 = ((int *)unk1D8)[arg0];
    }
    unk9C = unk1D0;
    return 1;
}
