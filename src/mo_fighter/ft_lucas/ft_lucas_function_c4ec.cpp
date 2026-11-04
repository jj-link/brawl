#include <ft/fighter.h>
#pragma force_active on

#define LV(n) virtual void dummy##n();

class LucasObject {
public:
    LV(8) LV(12) LV(16) LV(20)
    virtual unsigned int soundCheck(int, int);
    LV(28) LV(32) LV(36) LV(40)
    virtual float getLr();
    LV(48) LV(52) LV(56) LV(60) LV(64)
    virtual unsigned int getEtc();
    virtual int getStatus();
    LV(76) LV(80) LV(84) LV(88) LV(92) LV(96) LV(100) LV(104)
    LV(108) LV(112) LV(116) LV(120) LV(124) LV(128) LV(132) LV(136)
    LV(140) LV(144) LV(148) LV(152) LV(156) LV(160) LV(164) LV(168)
    LV(172) LV(176) LV(180) LV(184) LV(188) LV(192) LV(196) LV(200)
    LV(204) LV(208) LV(212) LV(216) LV(220) LV(224) LV(228) LV(232)
    LV(236) LV(240) LV(244) LV(248) LV(252) LV(256) LV(260) LV(264)
    LV(268) LV(272) LV(276) LV(280) LV(284) LV(288) LV(292) LV(296)
    LV(300) LV(304)
    virtual void play(int, int, int, int, int);
};

struct LucasPrefix8 {
    char pad[8];
};

struct LucasPrefix3C {
    char pad[0x3C];
};

class LucasIdView : public LucasPrefix3C {
public:
    LV(0) LV(4) LV(8) LV(12) LV(16) LV(20) LV(24) LV(28)
    LV(32) LV(36) LV(40) LV(44) LV(48) LV(52) LV(56) LV(60)
    LV(64) LV(68) LV(72) LV(76) LV(80) LV(84) LV(88) LV(92)
    LV(96) LV(100) LV(104) LV(108) LV(112) LV(116) LV(120) LV(124)
    LV(128) LV(132) LV(136) LV(140) LV(144) LV(148) LV(152) LV(156)
    LV(160) LV(164) LV(168) LV(172) LV(176) LV(180) LV(184) LV(188)
    LV(192) LV(196) LV(200) LV(204) LV(208) LV(212) LV(216) LV(220)
    LV(224) LV(228) LV(232) LV(236) LV(240) LV(244) LV(248) LV(252)
    LV(256) LV(260) LV(264) LV(268) LV(272) LV(276) LV(280) LV(284)
    LV(288) LV(292) LV(296) LV(300) LV(304) LV(308) LV(312) LV(316)
    LV(320) LV(324) LV(328) LV(332) LV(336) LV(340) LV(344) LV(348)
    LV(352) LV(356) LV(360) LV(364) LV(368) LV(372) LV(376) LV(380)
    LV(384) LV(388) LV(392) LV(396) LV(400) LV(404) LV(408) LV(412)
    LV(416) LV(420) LV(424) LV(428) LV(432) LV(436) LV(440) LV(444)
    LV(448) LV(452) LV(456) LV(460) LV(464) LV(468) LV(472)
    virtual int getId();
};

class LucasModel : public LucasPrefix8 {
public:
    LV(8) LV(12) LV(16) LV(20) LV(24) LV(28) LV(32) LV(36)
    LV(40) LV(44) LV(48) LV(52) LV(56) LV(60) LV(64) LV(68)
    LV(72) LV(76) LV(80) LV(84) LV(88) LV(92) LV(96) LV(100)
    LV(104) LV(108) LV(112) LV(116) LV(120) LV(124) LV(128) LV(132)
    LV(136)
    virtual int getValue(int);
};

class LucasResource : public LucasPrefix8 {
public:
    LV(8) LV(12) LV(16) LV(20)
    virtual LucasObject* getRes();
};

struct LucasModules {
    LucasResource* resource;
    LucasModel* model;
    void* unused;
    LucasObject* posture;
    char pad[0x54 - 0x10];
    LucasObject* sound;
    char pad2[0x70 - 0x58];
    LucasObject* status;
};

struct LucasAccesser {
    char pad[8];
    void* stage;
    char pad2[0xD8 - 0xC];
    LucasModules* modules;
};

#undef LV

extern "C" {
extern const char lbl_114_data_3400[], lbl_114_data_3C7C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_114_208F4(Fighter*, unsigned int, unsigned int, int, float, bool, bool);
}

extern "C" int fn_114_C4EC(Fighter* object, LucasAccesser* accesser) {
    int ownerId;
    bool flag;
    LucasResource* resource;
    unsigned int taskId;
    LucasObject* sound;
    Fighter* fighter;
    bool isStatus7F;
    fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->stage, 0x3C, lbl_114_data_3400, lbl_114_data_3C7C, short(1)));
    int status = accesser->modules->status->getStatus();
    isStatus7F = status == 0x7F;
    flag = false;
    unsigned int idx = status - 0x34;
    if (idx <= 4 && ((1 << idx) & 0x15)) {
        flag = true;
    }
    resource = accesser->modules->resource;
    taskId = fighter->m_taskId;
    LucasObject* posture = accesser->modules->posture;
    float direction = posture->getLr();
    ownerId = fn_27_111364(fighter->getOwner());
    LucasObject* res = resource->getRes();
    unsigned int resId = res->getEtc();
    fn_114_208F4(object, taskId, resId, ownerId, direction, isStatus7F, flag);
    if (flag) {
        sound = accesser->modules->sound;
        int id = reinterpret_cast<LucasIdView*>(object)->getId();
        if (sound->soundCheck(3, id) != 0) {
            LucasModel* model = accesser->modules->model;
            int value = model->getValue(0x12C);
            sound->play(3, value, 0xB, 1, 0);
        }
    }
    return 1;
}
