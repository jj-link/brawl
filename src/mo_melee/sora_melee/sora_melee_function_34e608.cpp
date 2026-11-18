#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <ft/fighter.h>
#include <mt/mt_prng.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Object_vptr_0* slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};

class TeamValue {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
};

class TeamModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual TeamValue* slot2();
};

struct CountData {
    char pad[0x10];
    unsigned int count;
};

struct Context {
    char pad[0x2148];
    CountData* data;
};

extern "C" {
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern const float lbl_27_rodata_7910[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
unsigned char fn_27_1119B8(void*);
void fn_27_3514CC(void*, unsigned int, void*, int, int, Vec3f*, int, int, float, float);
}

extern "C" int fn_27_34E608(void*, Context* self, soModuleAccesser* a, void* arg) {
    soPostureModule* posture;
    int work;
    TeamModule* team;
    unsigned int task;
    int index;

    Fighter* fighter = (Fighter*)__dynamic_cast(
        a->m_stageObject, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);

    int prev = a->m_enumerationStart->m_workManageModule->getInt(0x10000040);
    int prev2 = a->m_enumerationStart->m_workManageModule->getInt(0x10000041);
    int* choices = (int*)__alloca(self->data->count * sizeof(int));
    int i;
    int n = 0;

    for (i = 0; (unsigned int)i < self->data->count; ++i) {
        if (i != prev && i != prev2)
            choices[n++] = i;
    }

    int chosen = choices[randi(n)];
    a->m_enumerationStart->m_workManageModule->setInt(chosen, 0x10000040);
    a->m_enumerationStart->m_workManageModule->setInt(prev, 0x10000041);

    float value = 0.0f;
    Vec3f offset;
    offset.m_x = 2.5f;
    offset.m_y = 6.5f;
    offset.m_z = value;

    int node;
    if (fighter->soGetSubKind() == 0x12) {
        node = 0x1d;
        value = fn_27_1119B8(fighter->getOwner());
    } else {
        node = 0x1b1;
        offset.m_x = -3.0f;
        offset.m_y = 6.0f;
        offset.m_z = 0.0f;
    }

    Vec3f position = a->m_enumerationStart->m_modelModule->getNodeGlobalPosition(
        node, &offset, false, false);

    int old = a->m_enumerationStart->m_workManageModule->getInt(0x10000042);
    index = randi(4);
    if (old == index)
        index++;
    if (index >= 4)
        index = 0;

    a->m_enumerationStart->m_workManageModule->setInt(index, 0x10000042);

    const soModuleEnumeration* modules = a->m_enumerationStart;
    posture = modules->m_postureModule;
    team = (TeamModule*)modules->m_teamModule;
    task = a->m_stageObject->m_taskId;
    work = modules->m_workManageModule->getInt(0x10000046);

    fn_27_3514CC(self, task, arg, index, team->slot2()->slot2(), &position,
                 chosen, work, posture->getLr(), value);
    return 0;
}
