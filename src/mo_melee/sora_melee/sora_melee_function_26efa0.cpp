#pragma force_active on
extern "C" int getFrameCount__16gfModelAnimationFd(void*);

struct grAnimHolder {
    void* model;
};

class grGimmickMotionPath {
public:
    char pad0[0x48];
    grAnimHolder* m_anim;
    char pad1[0x160 - 0x4C];
    int m_endFrame;

    void applyEndFrame();
};

void grGimmickMotionPath::applyEndFrame() {
    m_endFrame = getFrameCount__16gfModelAnimationFd(m_anim->model);
}
