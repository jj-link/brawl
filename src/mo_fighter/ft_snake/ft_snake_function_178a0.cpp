#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mt/mt_prng.h>
#include <memory.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
};

struct SnakeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct SnakeInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    SnakeFlags flags;
};
struct SnakeParams {
    char pad[0x1c];
    int value;
    float chance;
};
struct SnakeObject : StageObject {
    char pad[0x23e8 - sizeof(StageObject)];
    SnakeParams* params;
};
extern "C" {
extern const float lbl_122_rodata_A0;
extern const float lbl_122_rodata_98;
Vec3f* fn_122_D580(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const SnakeInitialize*);
void fn_27_89544(void*, int);
void fn_27_894D4(void*, unsigned int);
void fn_122_178A0(SnakeObject* object, int resource, int team, int parameter, float facing) {
    Vec3f position;
    fn_122_D580(&position, lbl_122_rodata_A0, lbl_122_rodata_A0, lbl_122_rodata_A0);
    SnakeInitialize initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 1;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    fn_27_1D8370(object, &initialize);
    object->m_moduleAccesser->getWorkManageModule().setInt(object->params->value, 0x10000005);
    float random = randf();
    float chance = object->params->chance;
    if (chance > lbl_122_rodata_A0 && lbl_122_rodata_98 / chance >= random) {
        object->m_moduleAccesser->getVisibilityModule().setStatusDefault(0, 1, true);
        object->m_moduleAccesser->getVisibilityModule().setDefaultAll();
    }
    fn_27_89544(&object->m_moduleAccesser->getKineticModule(), 1);
    fn_27_89544(&object->m_moduleAccesser->getKineticModule(), 2);
    fn_27_894D4(&object->m_moduleAccesser->getKineticModule(), 3);
    object->m_moduleAccesser->getGroundModule().setCalcLineMove(false, 0);
    object->m_moduleAccesser->getGroundModule().setDetachChangeStatus(false);
}
}