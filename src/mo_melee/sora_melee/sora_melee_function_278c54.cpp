#pragma force_active on
extern "C" {
unsigned int fn_8004E958(void*);
unsigned int fn_8004E96C(void*);
unsigned int getFrameCount__16gfModelAnimationFd(void*);
float getFrame__16gfModelAnimationFd(void*);
void setFrame__16gfModelAnimationFd(void*, double);
void update__9grGimmickFf(void*, float);
extern void* g_GameGlobal;
extern const float lbl_27_rodata_4520;
}

struct Sub { char pad[0x1c]; unsigned char a, b, c, d; };

struct grMadein {
    char pad0[0x48];
    void*** unk48;
    char pad4C[0x110];
    Sub* unk15C;
    char pad160[0xC];
    unsigned char flags;
    char pad16D[3];
    float unk170;
    char pad174[0x2C];
    int unk1A0;
    void update(float);
};

void grMadein::update(float f) {
    flags &= ~0x10;
    if (fn_8004E96C(g_GameGlobal) == 1) {
        if (unk15C) {
            unk15C->a = 0;
            unk15C->b = 0;
            unk15C->c = 0;
            unk15C->d = 0;
        }
    }
    void* anim = *(void**)unk48;
    if (anim && unk1A0) {
        float fc = (float)getFrameCount__16gfModelAnimationFd(anim);
        if (getFrame__16gfModelAnimationFd(anim) >= fc && unk1A0) {
            setFrame__16gfModelAnimationFd(anim, lbl_27_rodata_4520);
            unk1A0 -= 1;
        }
    }
    if (fn_8004E958(g_GameGlobal) == 1) {
        if ((unsigned)((flags >> 1) & 1) == 1u) {
            flags &= ~2;
            unk170 += f;
        } else {
            unk170 = lbl_27_rodata_4520;
        }
    }
    update__9grGimmickFf(this, f);
}