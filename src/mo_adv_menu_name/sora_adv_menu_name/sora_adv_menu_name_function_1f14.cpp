#pragma force_active on
extern const float lbl_28_rodata_94;

extern "C" {
void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);

void fn_28_1F14(char* self) {
    setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(self + 0x148) + 0x14), lbl_28_rodata_94);
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x12c), 0xc, 0, 0);
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x12c), 0xd, 1, 0);
    *(void**)(self + 0x21c) = 0;
    *(void**)(self + 0x2d4) = 0;
}
}
