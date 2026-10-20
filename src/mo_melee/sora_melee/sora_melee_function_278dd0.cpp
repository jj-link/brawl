#include <types.h>
#pragma force_active on

class grMadein {
public:
    void initializeEntity();
    void endEntity();
    void setMotion(u32 motion);
};

extern "C" {
void fn_27_275C00(grMadein* self);
void setLoop__16gfModelAnimationFd(void* anim, bool loop);
extern const float lbl_27_rodata_4524;
}

void grMadein::initializeEntity() {
    void* anim = *(void**)((char*)this + 0x48);
    void* inner = *(void**)anim;
    if (inner) {
        setLoop__16gfModelAnimationFd(inner, false);
    }
    fn_27_275C00(this);
    endEntity();
    setMotion(0);
    *(float*)((char*)this + 0x64) = lbl_27_rodata_4524;
}
