#pragma force_active on
class Ground {
public:
    void enableCalcCollision();
private:
    char pad_00[0x6c];
    unsigned char m_flags_6c;
};

void Ground::enableCalcCollision() {
    m_flags_6c |= 8;
}
