#pragma force_active on
extern int lbl_8059C648;

typedef struct gfModelAnimation {
    char pad0[0x14];
    char *unk14;
} gfModelAnimation;

extern "C" void setLoopTexSrt__16gfModelAnimationFd(gfModelAnimation *self, int arg) {
    char *p = self->unk14;
    unsigned int idx = ((unsigned int)(-arg | arg) >> 31) << 2;
    int v = *(int *)((char *)&lbl_8059C648 + idx);
    if (p != 0) {
        *(int *)(p + 0x28) = v;
    }
}
