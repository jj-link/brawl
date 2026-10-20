#pragma force_active on
class Ground {
public:
    void disableCalcCollision();
private:
    unsigned char m_pad[0x6c];
    unsigned char m_flags;
};

void Ground::disableCalcCollision() {
    m_flags &= ~0x08;
}
