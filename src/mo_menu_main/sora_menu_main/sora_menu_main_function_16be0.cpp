#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
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
    virtual void slot23(s32, s32, s32);
};

struct Sub18 { char pad[0x10]; s32 v10; };
struct Sub1C { char pad[0x0C]; s32 vC; };

struct Elem {
    char pad0[0x14];
    void* anim;
    Sub18* p18;
    Sub1C* p1c;
};

struct Holder {
    Elem* slots[0x40];
};

struct CamTarget { char pad[0xE4]; f32 fE4; };
struct CamHolder { CamTarget* target; };
struct CameraController { char pad[0x48]; CamHolder* holder; };

struct RecordMenuData { char pad[0x28]; u8 b28 : 1; };

struct Menu {
    char pad0[0x42];
    u16 idx42;
    char pad1[0x634 - 0x44];
    s32 s634;
    char pad2[0x64C - 0x638];
    Holder* holder;
    char pad3[0x658 - 0x650];
    Class_728* p658;
    char pad4[0x664 - 0x65C];
    u32 s664;
};

extern "C" {
extern const float lbl_2_rodata_5E0[];
extern char lbl_2_data_1F78[];
extern void* g_sndSystem;
extern void* g_GameGlobal;

f32 getUpdateRate__16gfModelAnimationFv(void*);
f32 getFrame__16gfModelAnimationFd(void*, double);
void* getManager__15gfCameraManagerFv();
void fn_8001A108(void*, s32);
CameraController* getInstance__16CameraControllerFv();
RecordMenuData* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void fn_800557A8();
void fn_800B330C(void*, void*, s32);
u32 fn_18_12E0(Menu*);
void fn_18_17B0(Menu*, s32, s32, f32);
void playSE__9sndSystemF5SndIDiiii(void*, s32, s32, s32, s32, s32);
}

extern "C" s32 fn_2_16BE0(Menu* self, f32 dt) {
    const float* c = lbl_2_rodata_5E0;

    if (self->s664 == 2U) {
        if (c[0] == getUpdateRate__16gfModelAnimationFv(self->holder->slots[0x27]->anim)) {
            return 3;
        }
        return 0;
    }

    Elem* elem = self->holder->slots[0x27 + self->idx42];
    s32 kind;
    if (elem->p18 != 0) {
        kind = elem->p18->v10;
    } else if (elem->p1c != 0) {
        kind = elem->p1c->vC;
    } else {
        kind = -1;
    }

    switch (kind) {
    case 3:
        break;
    case 4:
        if (c[1] == getFrame__16gfModelAnimationFd(elem->anim, dt)) {
            fn_800B330C(self->holder->slots[0x27 + self->idx42], lbl_2_data_1F78 + 0x28, 1);
        }
        break;
    case 2:
        if (c[2] == getFrame__16gfModelAnimationFd(elem->anim, dt)) {
            fn_800B330C(self->holder->slots[0x27 + self->idx42], lbl_2_data_1F78 + 0x3C, 1);
        }
        break;
    }

    u32 flags = fn_18_12E0(self);
    if (((flags & 4) && self->idx42 == 1) || ((flags & 8) && self->idx42 == 0)) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x23, -1, 0, 0, -1);
        u16 old = self->idx42;
        Class_728* obj = self->p658;
        s32 nidx = old ^ 1;
        self->idx42 = (u16)nidx;
        obj->slot23(nidx + 0x3C, 1, 0);
        f32 f31;
        s32 flag;
        if (self->idx42 == 0) {
            f31 = c[3];
            flag = 1;
        } else {
            flag = 0;
            f31 = c[4];
        }
        fn_8001A108(getManager__15gfCameraManagerFv(), flag);
        getInstance__16CameraControllerFv()->holder->target->fE4 = f31;
        fn_800B330C(self->holder->slots[(self->idx42 ^ 1) + 0x27], lbl_2_data_1F78 + 0x14, 1);
        Holder* h = self->holder;
        h->slots[(self->idx42 ^ 1) + 0x27]->p1c = 0;
        fn_18_17B0(self, (self->idx42 ^ 1) + 0x27, 0x11, c[2]);
        fn_800B330C(self->holder->slots[self->idx42 + 0x27], lbl_2_data_1F78 + 0x3C, 1);
    } else if (flags & 0x20) {
        u32 idx;
        s32 i = 0;
        do {
            fn_800B330C(self->holder->slots[0x27 + i], lbl_2_data_1F78 + 0x64, 1);
            i++;
        } while (i < 2);
        idx = self->idx42;
        RecordMenuData* rm = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
        idx = (u8)idx;
        if (idx != rm->b28) {
            rm = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
            rm->b28 = idx;
            fn_800557A8();
        }
        self->s634 = 5;
        self->s664 = 2;
        return 1;
    }
    return 0;
}
