#include <types.h>
#include <gr/gr_gimmick_motion_path.h>
#include <gf/gf_model.h>
#include <st/st_trigger.h>

#pragma force_active on

extern "C" const char lbl_40_data_F168[];
extern "C" float lbl_40_rodata_630;
extern "C" void startup__9grGimmickFP9gfArchiveUlUl(void*, gfArchive*, unsigned long, unsigned long);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" grGimmickMotionPath* create__19grGimmickMotionPathFiPCcPCc(short, const char*, const char*);
extern "C" void createIsValidTrigger__9grGimmickFP13stTriggerData(void*, stTriggerData*);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(void*, u32*, u32, const char*);
extern "C" void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(gfModelAnimation*, nw4r::g3d::ScnMdl*);
extern "C" void fn_40_2E564(void*, void*, stTrigger*, stTriggerData*, int, int);

struct PathBase {
    char pad[0x3c];
};

class PathVirtual : public PathBase {
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
    virtual void startup(gfArchive*, unsigned long, gfSceneRoot::LayerType);
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
    virtual void setGimmickData(void*);
};

struct SoundParam {
    int id;
    u16 a, b, c, pad;
};

struct Data {
    float value;
    char pad04[2];
    u8 path;
    char pad07[0x119];
    SoundParam sounds[3];
    char pad144[0x9c];
    stTriggerData valid;
    stTriggerData trigger;
    char pad1e8[8];
    u8 flag;
};

struct Vec2 {
    float x, y;
};

struct SoundEntry {
    char pad[0xc];
    int id, a, c;
    u16 b, zero;
    Vec2 pos;
    char rest[4];
};

struct Callback {
    char pad[0x80];
    u32 node, type;
};

struct NameData {
    char first[1];
};

struct Self {
    char pad00[0x20];
    grGimmickMotionPath* child;
    char pad24[0x20];
    nw4r::g3d::ScnMdl** mdl;
    gfModelAnimation** anim;
    char pad4c[0x5c];
    SoundEntry* sound;
    char padac[0x10];
    Data* data;
    char padc0[0xc];
    grGimmickMotionPath* path;
    char padd0[4];
    Callback* callback;
    char padd8[8];
    u8 mode;
    char pade1[0x6f];
    Data* info;
    char observer[0x14];
    f32 value;
    u8 flag;
};

#pragma push
#pragma opt_propagation off
extern "C" void fn_40_3283C(Self* self, gfArchive* archive, u32 a, u32 b) {
    const char* names = lbl_40_data_F168;
    NameData* namesBase = (NameData*)names;
    char (NameData::*firstName)[1] = &NameData::first;

    startup__9grGimmickFP9gfArchiveUlUl(self, archive, a, b);
    self->info = self->data;
    self->value = self->data->value;
    self->flag = self->data->flag != 0;
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 2, 15);
    setCalcuCallbackRoot__9grGimmickFUl(self, 1);

    Data* data = self->info;
    if (data->path > 9 || data->path != 255) {
        self->path = create__19grGimmickMotionPathFiPCcPCc(
            (short)data->path, (const char*)&(namesBase->*firstName), names + 16);
        self->mode = 3;
        ((PathVirtual*)self->path)->setGimmickData(data);

        grGimmickMotionPath* path = self->path;
        *(Self**)((char*)path + 0x1c) = self;
        grGimmickMotionPath* cur = self->child;
        if (!cur)
            self->child = path;
        else {
            while (*(grGimmickMotionPath**)((char*)cur + 0x24))
                cur = *(grGimmickMotionPath**)((char*)cur + 0x24);
            *(grGimmickMotionPath**)((char*)cur + 0x24) = path;
        }

        ((PathVirtual*)self->path)->startup(archive, 0, (gfSceneRoot::LayerType)0);
    }

    createIsValidTrigger__9grGimmickFP13stTriggerData(self, &self->info->valid);
    u32 node = 0;
    getNodeIndex__6GroundFPUlUlPCc(self, &node, 0, names + 36);
    Callback* callback = self->callback;
    callback->node = node;
    callback->type = 2;

    unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*self->anim, *self->mdl);

    if (self->info->trigger.m_triggerId) {
        stTrigger* trigger =
            g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x32, &self->info->trigger);
        void* owner = self;
        if (owner)
            owner = (char*)self + 0x154;
        fn_40_2E564(self->observer, owner, trigger, &self->info->trigger, 1, 0);

        owner = self;
        if (owner)
            owner = (char*)self + 0x154;
        fn_40_2E564(self->observer, owner, trigger, &self->info->trigger, 0, 0);
    }

    ((grGimmick*)self)->createSoundWork(3, 1);
    ((grGimmick*)self)->createEffectWork(3);

    const float* zero1 = &lbl_40_rodata_630;
    Data* soundData1 = self->data;
    Vec2 q1;
    Vec2 p1;
    p1.x = *zero1;
    p1.y = *zero1;
    *(u32*)&q1 = *(u32*)&p1;
    *((u32*)&q1 + 1) = *((u32*)&p1 + 1);
    if (soundData1->sounds[0].id > 0) {
        self->sound[0].id = soundData1->sounds[0].id;
        self->sound[0].a = soundData1->sounds[0].a;
        self->sound[0].b = soundData1->sounds[0].b;
        self->sound[0].c = soundData1->sounds[0].c;
        self->sound[0].zero = 0;
        self->sound[0].pos = q1;
    }

    const float* zero2 = &lbl_40_rodata_630;
    Data* soundData2 = self->data;
    Vec2 p2;
    p2.x = *zero2;
    p2.y = *zero2;
    Vec2 p3;
    Vec2 q3;
    Vec2 q2 = p2;
    if (soundData2->sounds[1].id > 0) {
        self->sound[1].id = soundData2->sounds[1].id;
        self->sound[1].a = soundData2->sounds[1].a;
        self->sound[1].b = soundData2->sounds[1].b;
        self->sound[1].c = soundData2->sounds[1].c;
        self->sound[1].zero = 0;
        self->sound[1].pos = q2;
    }

    const float* zero3 = &lbl_40_rodata_630;
    Data* soundData3 = self->data;
    p3.x = *zero3;
    p3.y = *zero3;
    *(u32*)&q3 = *(u32*)&p3;
    *((u32*)&q3 + 1) = *((u32*)&p3 + 1);
    if (soundData3->sounds[2].id > 0) {
        self->sound[2].id = soundData3->sounds[2].id;
        self->sound[2].a = soundData3->sounds[2].a;
        self->sound[2].b = soundData3->sounds[2].b;
        self->sound[2].c = soundData3->sounds[2].c;
        self->sound[2].zero = 0;
        self->sound[2].pos = q3;
    }
}
#pragma pop
