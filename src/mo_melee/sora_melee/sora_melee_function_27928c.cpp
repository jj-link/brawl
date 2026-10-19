#pragma force_active on
class gfModelAnimation;

extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation* self, bool loop);

class grMadein {
public:
    void startEntity();
    void startEntityAutoLoop();
    char m_pad[0x48];
    struct Holder {
        gfModelAnimation* m_anim;
    }* m_holder;
};

void grMadein::startEntityAutoLoop() {
    gfModelAnimation* anim = m_holder->m_anim;
    startEntity();
    setLoop__16gfModelAnimationFd(anim, true);
}
