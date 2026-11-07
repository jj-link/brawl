#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
float getUpdateRate__16gfModelAnimationFv(void*);
float getFrame__16gfModelAnimationFd(void*);
void fn_800B330C(void*, char*, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
char* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
extern void* g_sndSystem;
extern void* g_GameGlobal;
extern char lbl_18_data_17B8[];
extern float lbl_18_rodata_298[];
}

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void slot22();
    virtual void fn_18_1198();
    virtual void fn_18_11AC();
};

struct Class_18D0_base {
    char p0[0x634];
    int s634;
    char p1[0x64c - 0x638];
    char* m64c;
    char p2[0x658 - 0x650];
    gfTask* o658;
    char p3[0x664 - 0x65c];
    u32 s664;
};
class Class_18D0 : public Class_18D0_base {
public:
    virtual void fn_18_95B0();
    virtual void fn_18_7C00();
    virtual void fn_18_B30();
    virtual void fn_18_8420();
    virtual void fn_18_85C4();
    virtual void fn_18_12D8();
    virtual void fn_18_8648(u32);
    char p4[0x738 - 0x66c];
    int s738;
    int s73c;
    char p5[0x761 - 0x740];
    u8 b761;
    u8 b762;
};

extern "C" u32 fn_18_12E0(Class_18D0*);

extern "C" int fn_18_8420(Class_18D0* self) {
    int a;
    int b;
    u32 in;
    float* ro = lbl_18_rodata_298;
    if (self->s664 == 2) {
        if (ro[44] == getUpdateRate__16gfModelAnimationFv(*(void**)(*(char**)(self->m64c + 0x150) + 0x14)))
            return 3;
        return 0;
    }
    if (ro[48] == getFrame__16gfModelAnimationFd(*(void**)(*(char**)(self->m64c + 0x150) + 0x14)))
        self->o658->fn_18_11AC();
    if ((int)self->s664 == 0 && ro[49] == getFrame__16gfModelAnimationFd(*(void**)(*(char**)(self->m64c + 0x150) + 0x14)))
        self->s664 = 1;
    if ((int)self->s664 != 0) {
        in = fn_18_12E0(self);
        self->fn_18_8648(in);
        u32 mask = 0x20;
        if (self->b761)
            mask |= 0x100;
        if (in & mask) {
            if (self->b762 == 1)
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
            fn_800B330C(*(void**)(self->m64c + 0x150), lbl_18_data_17B8 + 0x14, 0);
            a = self->s738;
            b = self->s73c;
            char* rec = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
            *(int*)(rec + 0x24) = b;
            *(int*)(rec + 0x20) = a;
            self->s634 = 0x1f;
            self->s664 = 2;
            return 1;
        }
    }
    return 0;
}
