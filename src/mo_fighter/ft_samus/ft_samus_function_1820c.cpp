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
    virtual int getInt(int);
    V(28) V(32) V(36)
    virtual unsigned int getParam();
    virtual float getLr();
    V(48) V(52) V(56) V(60) V(64)
    virtual unsigned int getEtc();
};

class Model {
public:
    char pad[8];
    V(8) V(12) V(16) V(20) V(24) V(28) V(32) V(36)
    V(40) V(44) V(48) V(52) V(56) V(60) V(64) V(68)
    V(72) V(76) V(80) V(84) V(88) V(92) V(96) V(100)
    V(104) V(108) V(112) V(116) V(120) V(124) V(128) V(132)
    V(136) V(140) V(144) V(148)
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
    V(484) V(488) V(492) V(496) V(500) V(504) V(508) V(512)
    V(516) V(520) V(524) V(528) V(532) V(536) V(540) V(544)
    V(548) V(552) V(556) V(560) V(564) V(568) V(572) V(576)
    V(580) V(584) V(588) V(592) V(596) V(600) V(604) V(608)
    V(612) V(616) V(620) V(624) V(628) V(632) V(636) V(640)
    V(644) V(648) V(652) V(656) V(660) V(664) V(668) V(672)
    V(676) V(680) V(684) V(688) V(692) V(696) V(700) V(704)
    V(708) V(712) V(716) V(720) V(724) V(728) V(732) V(736)
    V(740) V(744)
    virtual void* getOwner();
};

#undef V

struct Entry {
    unsigned int a, b, c, d;
};

struct CommonData {
    char pad[0xA4];
    Entry* entries;
};

struct Modules {
    Resource* resource;
    Model* model;
    void* unused;
    Object* posture;
    char pad[0x64 - 0x10];
    Object* work;
};

struct Accesser {
    char pad[8];
    void* stage;
    char pad2[0xD8 - 0xC];
    Modules* modules;
};

extern "C" {
extern const char lbl_94_data_4794[], lbl_94_data_5010[];
extern char g_ftCommonDataAccesser[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
CommonData* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
int fn_27_111364(void*);
void fn_94_1FBC4(void*, unsigned int, unsigned int, int,
                 unsigned int, unsigned int, unsigned int, int);

bool fn_94_1820C(void* request, Accesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->stage, 0x3C, lbl_94_data_4794, lbl_94_data_5010, 1));
    CommonData* common = getData__20ftCommonDataAccesserCF6ftKind(
        g_ftCommonDataAccesser, 0x18);
    Vec3 position = accesser->modules->model->position(0x36, false);
    accesser->modules->posture->getLr();

    unsigned int taskId;
    Resource* resource;
    int kind = accesser->modules->work->getInt(0x10000040);
    Entry* entry = &common->entries[kind];
    resource = accesser->modules->resource;
    taskId = fighter->taskId;

    fn_94_1FBC4(request, taskId, resource->getRes()->getEtc(), kind,
        resource->getRes()->getParam(), entry->a, entry->b,
        fn_27_111364(fighter->getOwner()));
    return true;
}
}
