#pragma force_active on
extern int lbl_8059C648;

typedef struct gfModelAnimation {
    char pad0[0xC];
    char *unkC;
} gfModelAnimation;

extern "C" void setLoopNode__16gfModelAnimationFd(gfModelAnimation *self, int arg) {
    char *p = self->unkC;
    unsigned int idx = ((unsigned int)(-arg | arg) >> 31) << 2;
    int v = *(int *)((char *)&lbl_8059C648 + idx);
    if (p) {
        *(int *)(p + 0x28) = v;
    }
}
