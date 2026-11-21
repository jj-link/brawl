#include <mu/mu_object.h>
#include <gm/gm_global.h>

#pragma force_active on

struct gfTask_base {
    char pad[0x3c];
};

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

struct Class_FA8_base {
    char pad[0x668];
};

class Class_FA8 : public Class_FA8_base {
public:
    virtual void fn_18_48E8();
    virtual void fn_18_20C8();
    virtual void fn_18_B30();
    virtual void fn_18_2BBC();
    virtual void fn_18_3338();
    virtual void fn_18_12D8();
    virtual void fn_18_3444();
};

struct Class_1688_base {
    char pad[0x668];
};

class Class_1688 : public Class_1688_base {
public:
    virtual void fn_18_68E0();
    virtual void fn_18_49D0();
    virtual void fn_18_B30();
    virtual void fn_18_519C();
    virtual void fn_18_58E8();
    virtual void fn_18_12D8();
    virtual void fn_18_5974();
};

struct Objects {
    char pad[0x78];
    MuObject* object;
};

struct Class_1750_base {
    char pad[0x634];
    int timer;
    char pad2[0x14];
    Objects* objects;
    char pad3[8];
    gfTask* task;
    char pad4[8];
    unsigned state;
};

class Class_1750 : public Class_1750_base {
public:
    virtual void fn_18_7A48();
    virtual void fn_18_6AC4();
    virtual void fn_18_B30();
    virtual void fn_18_6D44();
    virtual void fn_18_6EE0();
    virtual void fn_18_12D8();
    virtual void fn_18_6F48(unsigned);

    char pad5[0xc];
    unsigned char level;
    char pad6[7];
    unsigned long long mask;
    unsigned char flag;
};

struct Class_18D0_base {
    char pad[0x668];
};

class Class_18D0 : public Class_18D0_base {
public:
    virtual void fn_18_95B0();
    virtual void fn_18_7C00();
    virtual void fn_18_B30();
    virtual void fn_18_8420();
    virtual void fn_18_85C4();
    virtual void fn_18_12D8();
    virtual void fn_18_8648();
};

extern "C" {
extern float lbl_18_rodata_E0[];
extern char lbl_18_data_16E0[];

float getFrame__16gfModelAnimationFd(gfModelAnimation*);
unsigned fn_18_12E0(Class_1750*);
void fn_18_75F4(Class_1750*);
void fn_800B330C(MuObject*, void*, int);
}

extern "C" int fn_18_6D44(Class_1750* self) {
    const float* values = lbl_18_rodata_E0;

    if (self->state == 2) {
        if (values[3] == self->objects->object->m_modelAnim->getUpdateRate()) {
            return 3;
        }
        return 0;
    }

    if (values[6] == getFrame__16gfModelAnimationFd(self->objects->object->m_modelAnim)) {
        self->task->fn_18_11AC();
        fn_18_75F4(self);
    }

    if (self->state == 0 &&
        values[7] == getFrame__16gfModelAnimationFd(self->objects->object->m_modelAnim)) {
        self->state = 1;
    }

    if (self->state != 0) {
        unsigned flags = fn_18_12E0(self);
        self->fn_18_6F48(flags);

        int mask = 0x20;
        if (self->flag) {
            mask |= 0x100;
        }

        if (flags & mask) {
            fn_800B330C(self->objects->object, lbl_18_data_16E0 + 0x14, 0);

            unsigned long long extra = 0;
            extra |= 0xe000000000000ULL;
            unsigned int high = ((unsigned int*)&extra)[0];
            unsigned int hi = ((unsigned int*)&self->mask)[0];
            unsigned int lo = ((unsigned int*)&self->mask)[1];
            hi |= high;
            flags = *(unsigned char*)((char*)self + 0x678);

            *(unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap() = flags;
            gmGlobalRecord::MenuData* record = g_GameGlobal->getGlobalRecordMenuDatap();
            *(unsigned long long*)((char*)record + 8) =
                lo | ((unsigned long long)hi << 32);

            self->timer = 30;
            self->state = 2;
            return 1;
        }
    }

    return 0;
}
