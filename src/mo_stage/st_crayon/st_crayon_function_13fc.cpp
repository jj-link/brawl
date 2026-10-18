#pragma force_active on
class Ground {
public:
    unsigned char pad[0x6c];
    unsigned char m_flags;
    bool isEnableCalcCollision();
};

bool Ground::isEnableCalcCollision()
{
    return (m_flags >> 3) & 1;
}
