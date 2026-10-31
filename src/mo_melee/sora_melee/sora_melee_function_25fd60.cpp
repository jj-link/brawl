#pragma force_active on
struct gfModelAnimation;
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation* self, bool loop);

class Ground {
public:
    char m_pad[0x48];
    gfModelAnimation** m_anims;
    void setMotionLoop(bool loop, unsigned long idx);
};

void Ground::setMotionLoop(bool loop, unsigned long idx) {
    gfModelAnimation* anim = m_anims[idx];
    if (anim) {
        setLoop__16gfModelAnimationFd(anim, loop);
    }
}
