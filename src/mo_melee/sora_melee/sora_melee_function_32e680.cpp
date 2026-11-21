#include <so/stageobject.h>
#include <mt/mt_prng.h>
#pragma force_active on

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
    virtual int slot40();
};

class TeamValue {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int getValue();
};
class TeamModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual TeamValue* getValue();
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
extern const float lbl_27_rodata_7640[];
void* fn_27_149784(void*, int);
float fn_27_192278(void*, unsigned long);
void fn_27_33029C(void*, int, int, const Vec3f*, int, float, float, float, float, float);
}

extern "C" int fn_27_32E680(void* unused, StageObject& object, soModuleAccesser* accesser) {
    const float* const constants = lbl_27_rodata_7640;
    soModuleAccesser* acc = accesser;
    soWorkManageModule* work;
    soWorkManageModule* work2;
    int kind = ((Object_vptr_3c*)acc->m_stageObject)->slot40();
    Vec3f pos = acc->getPostureModule().getPos();
    float lr = acc->getPostureModule().getLr();
    acc->getPostureModule().getScale();
    float power = constants[0];
    float* data = (float*)fn_27_149784(&g_ftCommonDataAccesser, kind);
    float y, z;
    z = data[0x11];
    y = data[0x12];
    Vec3f offset;
    offset.m_y = y;
    offset.m_x = constants[1];
    offset.m_z = z;
    float angle = acc->getWorkManageModule().getFloat(0x21000004);
    if (kind == 5) {
        pos = acc->getModelModule().getNodeGlobalPosition(0x19c, &offset, false, false);
    } else {
        pos = acc->getModelModule().getNodeGlobalPosition(0x33, &offset, false, false);
    }
    work = acc->m_enumerationStart->m_workManageModule;
    float threshold = fn_27_192278(acc, 0xfa6);
    float strength = work->getFloat(0x11000014) / threshold;
    work2 = acc->m_enumerationStart->m_workManageModule;
    threshold = fn_27_192278(acc, 0xfa8);
    float scale = work2->getFloat(0x11000013) / threshold;
    float base = fn_27_192278(acc, 0xfa0);
    float range = fn_27_192278(acc, 0xfa1);
    angle = base + angle;
    angle += range * randf() - constants[2] * range;
    int task = acc->m_stageObject->m_taskId;
    TeamModule* team = (TeamModule*)acc->m_enumerationStart->m_teamModule;
    int teamValue = team->getValue()->getValue();
    fn_27_33029C(&object, task, teamValue, &pos, 0, lr, strength, scale, power, constants[3] * angle);
    return 0;
}
