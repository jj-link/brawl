#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_64D0;

class ModelModule {
public:
    char pad[8];
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36();
    virtual Vec3f getNodeGlobalPosition(unsigned int node, const Vec3f* offset, bool, bool); // 0x9c
};

class PostureModule {
public:
    virtual void s0(); virtual void s1();
    virtual void setPos(Vec3f* pos, float f); // 0x10
};

class GroundModule {
public:
    char pad[8];
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110();
    virtual float getValue(); // 0x1c4
};

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual float slot12(unsigned int); // 0x38
    virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67();
    virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
    virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
    virtual void slot76(); virtual void slot77(); virtual void slot78(); virtual void slot79();
    virtual void slot80(); virtual void slot81(); virtual void slot82(); virtual void slot83();
    virtual void slot84(); virtual void slot85(); virtual void slot86();
    virtual void slot87(bool); // 0x164
};

struct Accesser;

enum Situation { Situation_Ground = 0, Situation_Air = 1 };

class StatusModule {
public:
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual void change(Situation, Accesser*); // 0x14
};

struct Modules {
    char p0[0x4];
    ModelModule* model;
    char p8[0x4];
    PostureModule* posture;
    GroundModule* ground;
    char p14[0x40];
    Object_vptr_0* link;
    char p58[0xC];
    Object_vptr_0* work;
    char p68[0x8];
    StatusModule* status;
};

struct Accesser {
    char p0[0xD8];
    Modules* modules;
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    char p40[0x20];
    Accesser* accesser;
};

extern "C" void fn_27_2F3AAC(Object_vptr_3c* self, float value) {
    Accesser* acc = self->accesser;
    Vec3f offset;
    offset.m_x = lbl_27_rodata_64D0;
    offset.m_y = lbl_27_rodata_64D0;
    offset.m_z = lbl_27_rodata_64D0;
    Vec3f pos = acc->modules->model->getNodeGlobalPosition(0, &offset, false, false);
    float dy = acc->modules->work->slot12(0x11000001);
    pos.m_z = acc->modules->ground->getValue();
    pos.m_y += dy;
    acc->modules->posture->setPos(&pos, value);
    acc->modules->link->slot87(true);
    acc->modules->status->change(dy < lbl_27_rodata_64D0 ? Situation_Air : Situation_Ground, acc);
    self->slot43();
}
