#pragma force_active on
struct grCollision {
    char pad0[0x14];
    int unk14;
    int getLine(unsigned short arg);
};

int grCollision::getLine(unsigned short arg)
{
    return unk14 + arg * 0x12;
}
