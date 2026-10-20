#pragma force_active on
class Ground
{
public:
    void disableCalcCollision();

private:
    unsigned char padding[0x6C];
    unsigned char calcCollision;
};

void Ground::disableCalcCollision()
{
    calcCollision = static_cast<unsigned char>(calcCollision & ~0x08u);
}
