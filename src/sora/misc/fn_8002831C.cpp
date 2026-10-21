#pragma force_active on
typedef struct gfModelAnimation {
    char pad0[8];
    void* unk8;
} gfModelAnimation;

extern int lbl_8059C648;

extern "C" void setLoopVisible__16gfModelAnimationFd(gfModelAnimation* self, int flag) {
    void* p = self->unk8;
    unsigned int idx = ((unsigned int)(-flag | flag)) >> 31;
    int v = *(int*)((char*)&lbl_8059C648 + idx * 4);
    if (p != 0) {
        *(int*)((char*)p + 0x28) = v;
    }
}
