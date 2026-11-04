#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
float getUpdateRate__16gfModelAnimationFv(void*);
float getFrame__16gfModelAnimationFd(void*);
void fn_800B330C(void*, char*, int);
u32 fn_18_12E0(void*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void fn_80038570(void*, int);
void setFrameTex__8MuObjectFf(void*, float);
u8* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void fn_800557A8();

extern void* g_sndSystem;
extern void* lbl_805A0098;
extern void* g_GameGlobal;
extern char lbl_2_data_2040[];
extern const float lbl_2_rodata_5F8;
extern const float lbl_2_rodata_608;
}

struct Class728_base { char pad[0x3c]; };
class Class728 : public Class728_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23(int, int, int);
};

struct Mu {
    char pad[0x14];
    void* anim;
    char* a;
    char* b;
};

struct Self {
    char p0[0x42];
    u16 v42;
    char p1[0x634 - 0x44];
    int s634;
    char p2[0x64c - 0x638];
    char* m64c;
    char p3[0x658 - 0x650];
    Class728* o658;
    char p4[0x664 - 0x65c];
    u32 s664;
};

extern "C" int fn_2_17130(Self* self) {
    if (self->s664 == 2) {
        Mu* mu = *(Mu**)(self->m64c + 0xa4);
        if (lbl_2_rodata_5F8 == getUpdateRate__16gfModelAnimationFv(mu->anim))
            return 3;
        return 0;
    }

    Mu* mu = *(Mu**)(self->m64c + 0xa4);
    int v;
    if (mu->a)
        v = *(int*)(mu->a + 0x10);
    else if (mu->b)
        v = *(int*)(mu->b + 0xc);
    else
        v = -1;

    if (v == 0 && lbl_2_rodata_608 == getFrame__16gfModelAnimationFd(mu->anim))
        fn_800B330C(*(void**)(self->m64c + 0xa4), lbl_2_data_2040 + 0x14, 1);

    u32 in = fn_18_12E0(self);
    if (in & 0x10) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x24, -1, 0, 0, -1);
        self->v42 ^= 1;
        fn_80038570(lbl_805A0098, !(self->v42 - 1));
        self->o658->slot23(0x3f - self->v42, 1, 0);
        setFrameTex__8MuObjectFf(*(void**)(self->m64c + 0xa4), self->v42);
    } else if (in & 0x20) {
        u16 h = self->v42;
        if ((u8)h != getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal)[0x19]) {
            getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal)[0x19] = (u8)h;
            fn_800557A8();
        }
        fn_800B330C(*(void**)(self->m64c + 0xa4), lbl_2_data_2040 + 0x28, 1);
        self->s634 = 5;
        self->s664 = 2;
        return 1;
    }
    return 0;
}
