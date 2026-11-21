#include <so/so_module_accesser.h>
#include <mt/mt_prng.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_116_7384();
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
    virtual void* slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
};

struct Pad8 { char pad[8]; };
struct Resource : Pad8 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Object_vptr_0* slot4();
};
struct Params { char pad[0x14]; float value; int number; };

extern "C" {
extern const char lbl_116_data_6960[], lbl_116_data_2D00[];
extern const float lbl_116_rodata_20, lbl_116_rodata_24;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_116_10A30(Vec3f*, const Vec3f*);
void fn_116_1355C(void*, int, void*, int, Vec3f*, float, float, float, int, int);
}

extern "C" int fn_116_10800(void* object, soModuleAccesser* accesser) {
    void* fighter = __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_116_data_6960, lbl_116_data_2D00, short(1));
    Params* params = *(Params**)((char*)fighter + 0x18e8);
    soPostureModule* posture;
    Resource* resource;
    int taskId;
    int value;
    accesser->m_enumerationStart->m_workManageModule->getInt(0x20000000);
    float base = accesser->m_enumerationStart->m_workManageModule->getFloat(0x11000002);
    float angle = base + (lbl_116_rodata_20 * randf() - lbl_116_rodata_24);
    accesser->m_enumerationStart->m_workManageModule->setFloat(angle, 0x21000000);
    value = accesser->m_enumerationStart->m_workManageModule->getInt(0x10000005);
    Vec3f position;
    if (accesser->m_enumerationStart->m_statusModule->getStatusKind() == 1) {
        Vec3f raw = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(1, false);
        fn_116_10A30(&position, &raw);
    } else {
        Vec3f raw = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, false);
        fn_116_10A30(&position, &raw);
    }
    posture = accesser->m_enumerationStart->m_postureModule;
    resource = (Resource*)accesser->m_enumerationStart->m_resourceModule;
    taskId = *(int*)((char*)accesser->m_stageObject + 0x28);
    accesser = (soModuleAccesser*)randi(2);
    base = posture->getLr();
    void* target = resource->slot4()->slot12();
    fn_116_1355C(object, taskId, target, value, &position, base, angle, params->value, params->number, (int)accesser);
    return 0;
}