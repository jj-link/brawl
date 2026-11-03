#include <snd/snd_system.h>
#include <mu/mu_object.h>
#include <gf/gf_keep_fb.h>
#include <mu/adv/mu_adv_saveload.h>
#include <nw4r/g3d/g3d_scngroup.h>
#pragma force_active on

class Class_5648 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_1E5E0();
    virtual void fn_40_1E2A0();
    virtual void fn_40_1DE6C();
    virtual void fn_40_20D70();
    virtual void fn_40_20E2C();
    virtual void fn_40_2155C();
    virtual void fn_40_20A8C();
    virtual void fn_40_1DFBC();
    virtual void fn_40_20EE8();
};

class Class_6C68 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_24BA4();
    virtual void fn_40_1E2A0();
    virtual void fn_40_24864();
    virtual void fn_40_20D70();
    virtual void fn_40_20E2C();
    virtual void fn_40_2155C();
    virtual void fn_40_20A8C();
    virtual void fn_40_1DFBC();
    virtual void fn_40_20EE8();
};

class Class_83C8 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual void fn_40_28908();
    virtual void fn_40_28604();
    virtual void fn_40_281E8();
    virtual void fn_40_28D54();
    virtual void fn_40_28E10();
    virtual void fn_40_295B0();
    virtual void fn_40_28A38();
    virtual void fn_40_282E8();
    virtual void fn_40_28ECC();
};

class Class_CEC8 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_30C08();
    virtual void fn_40_1E2A0();
    virtual void fn_40_30890();
    virtual void fn_40_20D70();
    virtual void fn_40_20E2C();
    virtual void fn_40_2155C();
    virtual void fn_40_20A8C();
    virtual void fn_40_1DFBC();
    virtual void fn_40_20EE8();
};

class Class_D270 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual void fn_40_30D68();
    virtual void fn_40_28604();
    virtual void fn_40_30990();
    virtual void fn_40_28D54();
    virtual void fn_40_28E10();
    virtual void fn_40_295B0();
    virtual void fn_40_28A38();
    virtual void fn_40_282E8();
    virtual void fn_40_28ECC();
};

extern "C" {
extern void* g_gfSceneRoot;
extern char* g_gfApplication;
extern void* g_IfAdvMngr;
extern void* lbl_805A0348;
extern float lbl_40_rodata_B60;
extern unsigned char lbl_8049E01C[0x14];
void fn_800B9984(void*);
int fn_800B61C0(MuObject*);
unsigned char fn_800B8648(void*, int, int, int);
void fn_800B881C(void*, unsigned char);
void fn_80107E74(void*);
void fn_8010ED14(void*);
void fn_8010ED7C(void*);
void fn_8019D950(void*);
gfTask* fn_40_3DDEC(void*, int, int);
void fn_40_41834(gfTask*);
void fn_40_48A44(void*);
int fn_40_48C04(void*);
}

struct Stage {
    char pad0[0x44];
    int state;
    int mode;
    int result;
    char pad50[0x1A8];
    unsigned char heap;
    char pad1F9[3];
    muAdvSaveTask* save;
    gfTask* task;
    char param[0xA];
    unsigned char flag;
    char pad20F[0x15];
    MuObject* object;
    nw4r::g3d::ScnObj* scene;
};

inline void show(Stage* self) {
    nw4r::g3d::ScnGroup* group = *(nw4r::g3d::ScnGroup**)((char*)g_gfSceneRoot + 0x450);
    group->Insert(group->sceneItemsCount, self->scene);
    fn_8010ED14(lbl_805A0348);
    self->object->setFrameNode(lbl_40_rodata_B60);
}

extern "C" void fn_40_48664(Stage* self) {
    fn_800B9984((char*)self + 0x150);
    switch (self->state) {
    case 0:
        self->state = 0xB2;
    case 0xB2:
        if (self->flag == 0)
            self->state = 0xBC;
        else
            goto stateFF;
        break;
    case 0xBC:
        g_sndSystem->playSE((SndID)5, -1, 0, 0, -1);
        show(self);
        self->state = 0xC1;
        break;
    case 0xC1:
        if (fn_800B61C0(self->object))
            goto state12F;
        break;
    stateCB:
        self->state = 0xCB;
        break;
    case 0xCB: {
        self->heap = fn_800B8648(lbl_8049E01C, 1, 0x2B, 0);
        muAdvSaveTaskParam param;
        param.unk0 = self->mode;
        muAdvSaveTask* task = muAdvSaveTask::create(&param, (Heaps::HeapType)0x2A, 0x2B);
        if (self->save)
            self->save->exit();
        self->save = task;
        fn_8019D950(self->scene);
        fn_8010ED7C(lbl_805A0348);
        self->state = 0xDD;
        break;
    }
    case 0xDD:
        fn_80107E74(g_IfAdvMngr);
        if (self->save->unk1B8 == 1) {
            show(self);
            if (self->save)
                self->save->exit();
            self->save = 0;
            fn_800B881C(lbl_8049E01C, self->heap);
            self->state = 0xF3;
        }
        break;
    case 0xF3:
        self->state = 0xF4;
        break;
    case 0xF4:
        ((gfKeepFrameBuffer*)(g_gfApplication + 0xD0))->endKeepScreen();
        goto state12F;
    stateFF:
        self->state = 0xFF;
        break;
    case 0xFF: {
        gfTask* task = fn_40_3DDEC(self->param, 0x2A, 0x2B);
        if (self->task)
            self->task->exit();
        self->task = task;
        fn_8019D950(self->scene);
        fn_8010ED7C(lbl_805A0348);
        self->state = 0x108;
        break;
    }
    case 0x108:
        switch (*(int*)((char*)self->task + 0xC24)) {
        case 0:
        case 1:
            return;
        case 2:
            self->result = 7;
            goto state144;
        case 4:
            self->result = 6;
            goto state144;
        case 3:
        default:
            show(self);
            fn_40_41834(self->task);
            if (self->task)
                self->task->exit();
            self->task = 0;
        state12F:
            self->state = 0x12F;
            break;
        }
        break;
    case 0x12F: {
        fn_40_48A44(self);
        int result = fn_40_48C04(self);
        if (result == 5) {
            goto stateCB;
        } else if (result == 7) {
            goto stateFF;
        } else if (result != 0) {
            self->result = result;
        state144:
            self->state = 0x144;
        }
        break;
    }
    case 0x144:
        break;
    }
}
