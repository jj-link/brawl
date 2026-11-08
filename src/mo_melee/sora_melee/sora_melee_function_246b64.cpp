#include <snd/snd_system.h>
#pragma force_active on

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
};

struct SubObj {
    char pad[0x63];
    unsigned char flag63;
    unsigned char flag64;
    char pad65[3];
    int val68;
    int val6c;
};

struct ThisObj {
    char pad[0x40];
    unsigned char state;
    char pad41;
    unsigned char flag42;
    unsigned char flag43;
    SubObj* sub;
    float time;
    float val4c;
    char pad50[4];
    unsigned char flag54;
    char pad55[3];
    Object_vptr_3c* stage58;
    Object_vptr_3c* stage5c;
    char pad60[0x14];
    int val74;
};

extern "C" {
float fn_8004E94C(void*);
int fn_27_2423E4(int);
void fn_27_242404(int);
void fn_800DE508(void*, int);
void fn_800DCDB8(void*, int, int);
unsigned int fn_800DCDC0(void*);
void fn_27_109318(void*);

extern void* g_GameGlobal;
extern void* g_IfMngr;
extern void* g_ftManager;
extern const float lbl_27_rodata_3FA0[];
}

extern "C" void fn_27_246B64(ThisObj* self) {
    const float* ro = lbl_27_rodata_3FA0;

    if (self->flag43 == 1)
        return;
    if (self->flag42 == 1)
        return;

    float dt = fn_8004E94C(g_GameGlobal);
    self->time += dt;

    switch (self->state) {
    case 1: {
        if (self->val74 != 0 && fn_27_2423E4(self->val74) == 0)
            return;

        self->time = ro[0];
        SubObj* sub = self->sub;

        if (sub->flag63 != 0) {
            void* obj = *(void**)((char*)g_IfMngr + 0x44);
            *(int*)((char*)obj + 0x168) = -1;
            *((char*)obj + 0x16c) = 0;
            *(float*)((char*)obj + 0x170) = ro[1];
            fn_800DE508(obj, 1);
            g_sndSystem->playSE((SndID)0x1fda, -1, 0, 0, -1);
            self->state = 3;
            return;
        }

        if (sub->flag64 != 0) {
            void* obj = *(void**)((char*)g_IfMngr + 0x44);
            *(int*)((char*)obj + 0x168) = -1;
            *((char*)obj + 0x16c) = 0;
            *(float*)((char*)obj + 0x170) = ro[1];
            fn_800DE508(obj, 1);
            g_sndSystem->playSE((SndID)0x1fda, -1, 0, 0, -1);
            self->state = 3;
            return;
        }

        int v68 = sub->val68;
        int v6c = sub->val6c;
        fn_800DCDB8(g_IfMngr, v68, v6c + 1);
        g_sndSystem->playSE((SndID)(v68 + 0x1fe8), -1, 0, 0, -1);
        self->state = 2;
        return;
    }

    case 2: {
        if (fn_800DCDC0(g_IfMngr) == 0)
            return;

        void* obj = *(void**)((char*)g_IfMngr + 0x44);
        *(int*)((char*)obj + 0x168) = -1;
        *((char*)obj + 0x16c) = 0;
        *(float*)((char*)obj + 0x170) = ro[1];
        fn_800DE508(obj, 1);
        g_sndSystem->playSE((SndID)0x1fda, -1, 0, 0, -1);
        self->state = 3;
        self->time = ro[0];
        return;
    }

    case 3:
        self->val4c -= dt;
        if (self->time >= ro[2]) {
            fn_27_242404(self->val74);
            if (self->stage58)
                self->stage58->slot35();
            if (self->stage5c)
                self->stage5c->slot35();
            fn_27_109318(g_ftManager);
            g_sndSystem->playSE((SndID)0x1fdb, -1, 0, 0, -1);
            unsigned int flags = self->flag54 | 0x80;
            self->state = 4;
            self->time = ro[0];
            self->flag54 = flags;
            self->val4c = ro[0];
        }
        return;

    case 4: {
        void* obj = *(void**)((char*)g_IfMngr + 0x44);
        if (*(int*)((char*)obj + 4) == 0)
            self->state = 5;
        return;
    }

    case 5:
        break;

    default:
        return;
    }
}
