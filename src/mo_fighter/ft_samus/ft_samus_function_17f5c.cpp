#pragma force_active on
#define V(n) virtual void dummy##n();

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

class Object {
public:
    V(8) V(12) V(16) V(20)
    virtual unsigned int soundCheck(int, int);
    virtual void unk1C(int, int);
    V(32) V(36) V(40)
    virtual float getLr();
    V(48) V(52) V(56) V(60) V(64)
    virtual unsigned int getEtc();
    virtual int getStatus();
    V(76) V(80) V(84) V(88) V(92) V(96) V(100) V(104)
    V(108) V(112) V(116) V(120) V(124) V(128) V(132) V(136)
    V(140) V(144) V(148) V(152) V(156) V(160) V(164) V(168)
    V(172) V(176) V(180) V(184) V(188) V(192) V(196) V(200)
    V(204) V(208) V(212) V(216) V(220) V(224) V(228) V(232)
    V(236)
    virtual void unkF0(int, int);
    V(244) V(248) V(252) V(256) V(260) V(264) V(268) V(272)
    V(276) V(280) V(284) V(288) V(292) V(296) V(300) V(304)
    virtual void play(int, int, int, int, int);
    V(312) V(316) V(320) V(324) V(328) V(332) V(336) V(340)
    V(344) V(348) V(352) V(356) V(360) V(364) V(368) V(372)
    V(376) V(380) V(384) V(388) V(392) V(396) V(400)
    virtual void playSe(int, int, int);
};

class Model {
public:
    char pad[8];
    V(8) V(12) V(16) V(20) V(24) V(28) V(32) V(36)
    V(40) V(44) V(48) V(52) V(56) V(60) V(64) V(68)
    V(72) V(76) V(80) V(84) V(88) V(92) V(96) V(100)
    V(104) V(108) V(112) V(116) V(120) V(124) V(128) V(132)
    V(136)
    virtual int getValue(int);
    V(144) V(148)
    virtual Vec3 position(int, bool);
};

class Resource {
public:
    char pad[8];
    V(8) V(12) V(16) V(20)
    virtual Object* getRes();
};

class Fighter {
public:
    char pad[0x28];
    unsigned int taskId;
    char pad2[0x10];
    V(8) V(12) V(16) V(20) V(24) V(28) V(32) V(36)
    V(40) V(44) V(48) V(52) V(56) V(60) V(64) V(68)
    V(72) V(76) V(80) V(84) V(88) V(92) V(96) V(100)
    V(104) V(108) V(112) V(116) V(120) V(124) V(128) V(132)
    V(136) V(140) V(144) V(148) V(152) V(156) V(160) V(164)
    V(168) V(172) V(176) V(180) V(184) V(188) V(192) V(196)
    V(200) V(204) V(208) V(212) V(216) V(220) V(224) V(228)
    V(232) V(236) V(240) V(244) V(248) V(252) V(256) V(260)
    V(264) V(268) V(272) V(276) V(280) V(284) V(288) V(292)
    V(296) V(300) V(304) V(308) V(312) V(316) V(320) V(324)
    V(328) V(332) V(336) V(340) V(344) V(348) V(352) V(356)
    V(360) V(364) V(368) V(372) V(376) V(380) V(384) V(388)
    V(392) V(396) V(400) V(404) V(408) V(412) V(416) V(420)
    V(424) V(428) V(432) V(436) V(440) V(444) V(448) V(452)
    V(456) V(460) V(464) V(468) V(472) V(476) V(480)
    virtual int getId();
    V(488) V(492) V(496) V(500) V(504) V(508) V(512) V(516)
    V(520) V(524) V(528) V(532) V(536) V(540) V(544) V(548)
    V(552) V(556) V(560) V(564) V(568) V(572) V(576) V(580)
    V(584) V(588) V(592) V(596) V(600) V(604) V(608) V(612)
    V(616) V(620) V(624) V(628) V(632) V(636) V(640) V(644)
    V(648) V(652) V(656) V(660) V(664) V(668) V(672) V(676)
    V(680) V(684) V(688) V(692) V(696) V(700) V(704) V(708)
    V(712) V(716) V(720) V(724) V(728) V(732) V(736) V(740)
    V(744)
    virtual void* getOwner();
};

#undef V

struct Modules {
    Resource* resource;
    Model* model;
    void* unused;
    Object* posture;
    char pad[0xC];
    Object* unk1C;
    char pad2[0x34];
    Object* sound;
    char pad3[0xC];
    Object* unk64;
    char pad4[0x8];
    Object* status;
};

struct Accesser {
    char pad[8];
    void* stage;
    char pad2[0xD8 - 0xC];
    Modules* modules;
};

extern "C" {
extern const char lbl_94_data_4794[], lbl_94_data_5010[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
int fn_27_5013C(void*);
void* fn_94_17DDC();
void fn_94_1CE0C(Fighter*, unsigned int, unsigned int, int,
                 float, const Vec3*, bool, bool, int);

bool fn_94_17F5C(void* arg0, Accesser* arg1) {
    Fighter* request;
    bool var28;
    bool var27;
    Resource* resource;
    unsigned int taskId;
    Fighter* fighter;
    Object* sound;
    int id;

    request = static_cast<Fighter*>(arg0);
    fighter = static_cast<Fighter*>(__dynamic_cast(
        arg1->stage, 0x3C, lbl_94_data_4794, lbl_94_data_5010, 1));

    Vec3 position = arg1->modules->model->position(0x36, false);
    float direction = arg1->modules->posture->getLr();

    int st = arg1->modules->status->getStatus();
    var28 = true;
    if (st != 0x113 && st != 0x114) {
        var28 = false;
    }

    var27 = false;
    if ((unsigned int)(st - 0x34) <= 4 && ((1 << (st - 0x34)) & 0x15)) {
        var27 = true;
    }

    id = fn_27_5013C(fn_94_17DDC());
    arg1->modules->unk64->unk1C(id, 0x10000041);
    if (id != -1) {
        arg1->modules->unk1C->unkF0(0, id);
    }

    resource = arg1->modules->resource;
    taskId = fighter->taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    unsigned int resId = resource->getRes()->getEtc();

    fn_94_1CE0C(request, taskId, resId, ownerId, direction, &position,
                 var28, var27, id);

    sound = arg1->modules->sound;
    if (var27) {
        if (sound->soundCheck(3, request->getId()) != 0) {
            Model* model = arg1->modules->model;
            int value = model->getValue(0x12C);
            sound->play(3, value, 0xA, 0x11, 0);
        }
    } else if (sound->soundCheck(6, request->getId()) != 0) {
        sound->playSe(6, 0, 1);
    }

    return true;
}
}
