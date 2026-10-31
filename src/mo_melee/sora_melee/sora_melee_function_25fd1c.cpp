#pragma force_active on
typedef unsigned long u32;

extern "C" void setFrame__16gfModelAnimationFd(void* anim, double frame);

class Ground {
public:
    void setMotionFrame(float frame, u32 idx);

private:
    char m_pad[0x48];
    void** m_motionAnims;
};

void Ground::setMotionFrame(float frame, u32 idx) {
    void* anim = m_motionAnims[idx];
    if (anim) {
        setFrame__16gfModelAnimationFd(anim, frame);
    }
}
