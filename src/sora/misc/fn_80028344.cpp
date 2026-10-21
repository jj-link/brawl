#pragma force_active on
typedef unsigned int u32;

extern int lbl_8059C648[2];

typedef struct Inner {
    char pad0[0x28];
    int val;
} Inner;

typedef struct gfModelAnimation {
    char pad0[0x10];
    Inner *unk10;
} gfModelAnimation;

extern "C" void setLoopTex__16gfModelAnimationFd(gfModelAnimation *self, int arg) {
    Inner *p = self->unk10;
    int v = lbl_8059C648[arg != 0];
    if (p != 0) {
        p->val = v;
    }
}
