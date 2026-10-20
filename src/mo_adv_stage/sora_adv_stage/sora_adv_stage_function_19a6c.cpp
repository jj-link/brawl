#pragma force_active on
class Ground {
public:
    unsigned char padding[0x6C];
    unsigned char flags;

    void enableCalcCollision();
};

void Ground::enableCalcCollision() {
    flags |= 0x08;
}
