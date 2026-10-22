#pragma force_active on
extern "C" double fn_800F5344(void);
extern "C" float getFrame__16gfModelAnimationFd(void *this_, double frame);
extern "C" void playSE__9sndSystemF5SndIDiiii(void *this_, int id, int a, int b, int c, int d);
extern void *g_sndSystem;

typedef struct Inner {
    char pad[0x14];
    void *anim;
} Inner;

typedef struct Obj {
    char pad[0x88];
    int state;
    char pad2[0x10];
    Inner *inner;
} Obj;

extern "C" void fn_800F6520(Obj *arg0) {
    double f;
    int frame;
    f = fn_800F5344();
    if (arg0->state == 2) {
        frame = (int)getFrame__16gfModelAnimationFd(arg0->inner->anim, f);
        if (frame == 0x2C) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0xEA, -1, 0, 0, -1);
        }
    }
}
