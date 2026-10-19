#pragma force_active on
extern "C" unsigned int fn_8018E3C0(void*);

class Ground {
public:
    void setDontMoveGround();
};

void Ground::setDontMoveGround() {
    if (fn_8018E3C0(reinterpret_cast<char*>(this) + 0x40) != 1)
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x6D) &= ~0x08;
}
