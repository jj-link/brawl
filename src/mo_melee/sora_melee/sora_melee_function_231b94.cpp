#pragma force_active on
typedef unsigned char u8;

class Ground {
public:
    u8 m_pad[0x6c];
    u8 m_flags;
    void enableCalcCollision();
};

void Ground::enableCalcCollision() {
    m_flags |= 0x8;
}
