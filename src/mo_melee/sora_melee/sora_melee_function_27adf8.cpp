#pragma force_active on
typedef unsigned char u8;

class Message {
public:
    void changeMsgBuf(int index);
    void clearMsgBuf();
};

class grStadiumVision {
public:
    void setDisplay(bool flag);

private:
    u8 m_pad0[0x160];
    struct {
        u8 display : 1;
        u8 rest : 7;
    } m_flags;
    u8 m_pad1[0x170 - 0x161];
    Message* m_message;
};

void grStadiumVision::setDisplay(bool flag) {
    m_flags.display = flag;
    if (!m_flags.display) {
        for (int i = 0; i < 5; i++) {
            m_message->changeMsgBuf(i);
            m_message->clearMsgBuf();
        }
    }
}
