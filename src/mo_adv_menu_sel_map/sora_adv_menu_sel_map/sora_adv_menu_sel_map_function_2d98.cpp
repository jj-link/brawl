#pragma force_active on
extern "C" void fn_800B5328(void* p);

class gfModelAnimation {
public:
    double getFrame(double frame);
};

struct AnimWrapper {
    char pad0[0x14];
    gfModelAnimation* inner;
};

struct AdvMenuSel {
    char pad0[0x40];
    int nextState;
    int state;
    char pad2[0x1c8 - 0x48];
    AnimWrapper* anim;
    char pad3[0x4a4 - 0x1cc];
    void* field4a4;
    char pad4[0x4c8 - 0x4a8];
    unsigned char flag;
};

extern "C" void* fn_31_2D98(AdvMenuSel* self) {
    AnimWrapper* anim = self->anim;
    fn_800B5328(anim);
    double frame;
    anim->inner->getFrame(frame);
    switch (self->state) {
    case 10:
        self->nextState = 10;
        break;
    case 7:
        self->nextState = 7;
        break;
    case 8:
        self->nextState = 8;
        break;
    case 9:
        self->nextState = 9;
        break;
    }
    self->flag = 1;
    return self->field4a4;
}
