#pragma force_active on
struct MsgBuf {
    char pad0[0x4C];
    int unk4C;
    unsigned char* unk50;
};

class Message {
public:
    char pad0[0x1D0];
    MsgBuf* unk1D0;
    void clearMsgBuf();
};

void Message::clearMsgBuf() {
    this->unk1D0->unk4C = 0;
    this->unk1D0->unk50[this->unk1D0->unk4C] = 1;
}
