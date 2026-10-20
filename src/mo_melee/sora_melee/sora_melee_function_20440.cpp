#pragma force_active on
struct AnimState {
    unsigned char padding[0x14];
    float frame;
    float startFrame;
    float savedFrame;
    float frameAhead;
    unsigned char loop : 1;
    unsigned char unused : 1;
    unsigned char reverse : 1;
    unsigned char remaining : 5;
};

extern const float lbl_27_rodata_370;

extern "C" bool fn_27_20440(const AnimState* p) {
    if (p->reverse == 0 && p->loop == 1 &&
        p->frame >= lbl_27_rodata_370 &&
        p->frame < p->frameAhead &&
        p->frame < p->startFrame) {
        return true;
    }
    return false;
}
