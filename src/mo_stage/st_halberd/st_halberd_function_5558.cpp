#include <st/module.h>
#pragma force_active on

extern "C" {

void setFrame__16gfModelAnimationFd(void*, double);

class Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setFrame(double) = 0;
};

struct Anim {
    char pad[0xC];
    Iface* a;
    char pad2[8];
    Iface* b;
};

struct Host {
    char pad[0x48];
    Anim** anims;
    char pad2[0x164 - 0x4C];
    unsigned char flag;
};

void fn_57_5558(Host* self, int index, double frame) {
    Anim* anim = self->anims[index];
    if (anim != NULL) {
        if (self->flag == 0) {
            setFrame__16gfModelAnimationFd(anim, frame);
        } else {
            anim->a->setFrame(frame);
            anim->b->setFrame(frame);
        }
    }
}

}
