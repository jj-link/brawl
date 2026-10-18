#pragma force_active on
typedef unsigned char u8;

class Ground {
public:
    u8 m_pad[0x6c];
    u8 m_flags;
    bool isEnableCalcCollision();
};

bool Ground::isEnableCalcCollision() {
    return (m_flags >> 3) & 1;
}
