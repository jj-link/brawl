#include <types.h>
#include <gr/gr_gimmick.h>
#include <gf/gf_model.h>
#include <it/it_manager.h>
#include <snd/snd_system.h>
#include <st/st_trigger.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(unsigned long, unsigned long, void*);
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97(unsigned long, unsigned long);
};

struct M2 { unsigned int w[2]; };
struct V3 { M2 ab; unsigned int c; };
struct M10 { unsigned int w[10]; };
struct Blob {
    M2 head;
    V3 v[6];
    M10 mid;
    M2 tail;
};

struct Obj1a0 {
    unsigned int m0;
    char pad4[0x34];
    int m38;
    unsigned int m3c;
};

struct Obj44 {
    void* m0;
    void* m4;
};

class GimmickObj : public Object_vptr_3c {
public:
    char pad40[4];
    Obj44* m44;
    Obj44* m48;
    char pad4c[0x6c - 0x4c];
    unsigned char m6c;
    char pad6d[0xd4 - 0x6d];
    Blob* md4;
    char padd8[4];
    int mdc;
    char pade0[0x150 - 0xe0];
    int m150;
    char pad154[0x194 - 0x154];
    Blob* m194;
    char pad198[0x1a0 - 0x198];
    Obj1a0* m1a0;
    int m1a4;
    unsigned int m1a8;
    float m1ac;
    char pad1b0[4];
    unsigned char m1b4;
};

struct Pair { int a; int b; };

extern "C" {
extern const float lbl_40_rodata_848;
extern const float lbl_40_rodata_8D8;
extern unsigned char lbl_40_data_15E7C[];
void getPos__9grGimmickFv(Vec3f* out, grGimmick* self);
itManager* getInstance__9itManagerFv();
void fn_27_2AA7AC(void* mgr, Pair pair, int a, Vec3f* pos, int c, int d, int e);
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
void setFrame__16gfModelAnimationFd(void* anim, double frame);
void setNodeVisibility__6GroundFbUlPCcbb(Ground* self, bool set, unsigned long mdl, const char* node, bool rec, bool rec2);
void playSE__9sndSystemF5SndIDiiii(void* self, int id, int a, int b, int c, int d);
void startGimmickEffect__9grGimmickFUl(void* self, unsigned long index);
void setTriggerFlag__12stTriggerMngFP13stTriggerData(void* self, void* data);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void* self, void* mdl);
}

extern "C" void fn_40_3D138(GimmickObj* self) {
    if (self->m1a8 < self->m1a0->m3c) {
        float sp30[3];
        Vec3f sp24;
        Vec3f sp18;
        Pair sp10;
        sp10.a = 0x3d;
        sp10.b = self->m1a4;
        getPos__9grGimmickFv(&sp18, (grGimmick*)self);
        float py = ((float*)&sp18)[1];
        float f31 = lbl_40_rodata_8D8 + py;
        getPos__9grGimmickFv(&sp24, (grGimmick*)self);
        sp30[0] = ((float*)&sp24)[0];
        sp30[1] = f31;
        sp30[2] = lbl_40_rodata_848;
        fn_27_2AA7AC((void*)getInstance__9itManagerFv(), sp10, self->m1a0->m38, (Vec3f*)sp30, -1, -1, -1);
        {
            Blob* dst = self->m194;
            Blob* src = self->md4;
            dst->head.w[0] = src->head.w[0];
            dst->head.w[1] = src->head.w[1];
            dst->v[0] = src->v[0];
            dst->v[1] = src->v[1];
            dst->v[2] = src->v[2];
            dst->v[3] = src->v[3];
            dst->v[4] = src->v[4];
            dst->v[5] = src->v[5];
            dst->mid = src->mid;
            dst->tail = src->tail;
        }
        void* m = self->m44->m4;
        self->mdc = 0;
        *(void**)((char*)m + 0x11c) = (char*)self + 0xd0;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
        Blob* md = self->md4;
        *(unsigned short*)((char*)m + 0x122) = (unsigned short)md->head.w[0];
        ((Object_vptr_0*)self->m44->m4)->slot6(0x10001, 0, md);
        setFrame__16gfModelAnimationFd(self->m48->m4, lbl_40_rodata_848);
        self->m6c &= ~0x2;
        self->slot71();
        self->m6c &= ~0x2;
        unsigned int n = self->m1a8 + 1;
        self->m1a8 = n;
        if (n >= self->m1a0->m3c) {
            self->slot97(0, 0);
            setNodeVisibility__6GroundFbUlPCcbb((Ground*)self, 0, 0, (const char*)lbl_40_data_15E7C, 0, 0);
            unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(self->m48->m0, self->m44->m0);
            self->m150 = 1;
            self->m1ac = lbl_40_rodata_848;
        }
        if (self->m1b4 == 0) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x226d, -1, 0, 0, -1);
        } else {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2286, -1, 0, 0, -1);
        }
        startGimmickEffect__9grGimmickFUl((grGimmick*)self, 0);
        setTriggerFlag__12stTriggerMngFP13stTriggerData(g_stTriggerMng, (char*)self->m1a0 + 0x50);
    }
}
