#pragma force_active on
typedef struct gfModelAnimation {
    char pad0[0x18];
    void* unk18;
} gfModelAnimation;

extern int lbl_8059C648;

extern "C" void setLoopMatCol__16gfModelAnimationFd(gfModelAnimation* self, int arg) {
    void* p = self->unk18;
    unsigned int idx = ((unsigned int)(-arg | arg) >> 31) << 2;
    int v = *(int*)((char*)&lbl_8059C648 + idx);
    if (p != 0) {
        *(int*)((char*)p + 0x28) = v;
    }
}
