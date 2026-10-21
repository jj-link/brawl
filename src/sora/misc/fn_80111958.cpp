#pragma force_active on
struct Joint {
    unsigned char data[0x60];
};

struct grCollision {
    unsigned char pad[0x18];
    Joint *joints;
    Joint *getJoint(unsigned short index);
};

Joint *grCollision::getJoint(unsigned short index)
{
    return &this->joints[index];
}
