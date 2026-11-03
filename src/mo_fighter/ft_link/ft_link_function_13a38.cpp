#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <memory.h>
#include <math.h>
#pragma force_active on

struct LinkParam {
    char pad0[4];
    int v4;
    int v8;
    float vc;
    float v10;
    float v14;
    char pad1[4];
    float v1c;
};

struct LinkBase {
    unsigned char pad0[0x3c];
};

struct LinkFighterObject : LinkBase {
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
    unsigned char pad1[0x60 - 0x40];
    soModuleAccesser* accesser;
    unsigned char pad2[0x20e4 - 0x64];
    LinkParam* param;
};

class LinkCenterView {
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
    virtual unsigned long long getParentShapeCenterPos(unsigned int);
};

extern "C" {
extern const char lbl_93_data_8DD0[];
extern const char lbl_93_data_30FC[];
extern const float lbl_93_rodata_80;
extern const float lbl_93_rodata_88;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA868(void*);
void fn_93_13DB8(Vec2f*, float, float);
void fn_93_DAEC(Vec2f*, const Vec2f*);

void fn_93_13A38(void* self, float farg0, float farg1, unsigned int arg1);
}

extern "C" void fn_93_13A38(void* self, float farg0, float farg1, unsigned int arg1) {
    LinkFighterObject* fighter = static_cast<LinkFighterObject*>(self);
    float sn;
    float var_f30;
    float f29;

    Vec3f pos = fighter->accesser->getModelModule().getNodeGlobalPosition(3, false);
    pos.m_z = fighter->accesser->getGroundModule().getZ();
    Vec3f rot = fighter->accesser->getModelModule().getNodeGlobalRotation(3, false);
    rot.m_y = fighter->param->v14;
    fighter->accesser->getPostureModule().init(&pos, farg0);

    Vec2f shapePos;
    unsigned long long bits = reinterpret_cast<LinkCenterView*>(
        fighter->accesser->m_enumerationStart->m_linkModule)->getParentShapeCenterPos(3);
    __memcpy(&shapePos, &bits, sizeof(shapePos));
    fighter->accesser->getGroundModule().setShapeSafePos(&shapePos, 0);
    fn_27_1DA868(self);

    int var_r4;
    if (arg1 == 1) {
        var_r4 = fighter->param->v8;
        var_f30 = fighter->param->v10;
    } else {
        var_r4 = fighter->param->v4;
        var_f30 = fighter->param->vc;
    }
    fighter->accesser->getWorkManageModule().setInt(var_r4, 0x10000005);
    fighter->accesser->getWorkManageModule().setFloat(farg1, 0x11000001);

    Vec3f rotA;
    rotA.m_x = lbl_93_rodata_80;
    rotA.m_y = lbl_93_rodata_80;
    rotA.m_z = lbl_93_rodata_88 * farg1;
    fighter->accesser->getPostureModule().setRot(&rotA, 0);
    fighter->accesser->getPostureModule().setRot(&rot, 1);

    fighter->slot43();

    fighter->accesser->getStatusModule().changeStatusRequest(2, fighter->accesser);

    char* energy = static_cast<char*>(__dynamic_cast(
        fighter->accesser->getKineticModule().getEnergy(0), 0, lbl_93_data_8DD0, lbl_93_data_30FC, 1));
    f29 = fighter->param->v1c;

    sn = sin(farg1);
    float cs = cos(farg1);
    Vec2f v10;
    fn_93_13DB8(&v10, var_f30 * cs, var_f30 * sn);
    fn_93_DAEC(reinterpret_cast<Vec2f*>(energy + 8), &v10);

    sn = sin(farg1);
    float cs2 = cos(farg1);
    Vec2f v8;
    fn_93_13DB8(&v8, -f29 * cs2, -f29 * sn);
    fn_93_DAEC(reinterpret_cast<Vec2f*>(energy + 0x10), &v8);

    fighter->accesser->getWorkManageModule().onFlag(0x12000003);
    fighter->accesser->getWorkManageModule().offFlag(0x12000004);
}
