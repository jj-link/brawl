#pragma force_active on
typedef unsigned int u32;

#define SLOT(n) virtual void slot##n();

struct Work {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20) SLOT(24)
    virtual void setInt(int, u32);
    SLOT(32) SLOT(36) SLOT(40) SLOT(44) SLOT(48) SLOT(52) SLOT(56)
    virtual void setFloat(float, u32);
    SLOT(64) SLOT(68) SLOT(72)
    virtual u32 isFlag(u32);
    virtual void onFlag(u32);
    virtual void offFlag(u32);
};

struct Control {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132)
    SLOT(136) SLOT(140) SLOT(144) SLOT(148)
    SLOT(152) SLOT(156) SLOT(160) SLOT(164)
    SLOT(168) SLOT(172) SLOT(176) SLOT(180)
    SLOT(184) SLOT(188) SLOT(192) SLOT(196)
    SLOT(200) SLOT(204) SLOT(208) SLOT(212)
    SLOT(216) SLOT(220) SLOT(224)
    virtual void call(int, int, int, int);
};

struct Area {
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    virtual void on(int);
    virtual void off(int);
};

struct Model {
    char pad[8];
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132)
    SLOT(136) SLOT(140) SLOT(144) SLOT(148)
    SLOT(152) SLOT(156) SLOT(160) SLOT(164)
    SLOT(168) SLOT(172) SLOT(176) SLOT(180)
    SLOT(184) SLOT(188) SLOT(192) SLOT(196)
    SLOT(200) SLOT(204) SLOT(208) SLOT(212)
    SLOT(216) SLOT(220) SLOT(224) SLOT(228)
    SLOT(232) SLOT(236) SLOT(240) SLOT(244)
    SLOT(248) SLOT(252) SLOT(256) SLOT(260)
    SLOT(264) SLOT(268) SLOT(272) SLOT(276)
    SLOT(280) SLOT(284) SLOT(288) SLOT(292)
    SLOT(296) SLOT(300) SLOT(304)
    virtual void set(bool);
};

struct Modules {
    char pad0[4];
    Model* model;
    char pad8[0x54];
    Control* control;
    char pad60[4];
    Work* work;
    char pad68[0x5c];
    Area* area;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad0[0x3c];
    SLOT(8) SLOT(12) SLOT(16) SLOT(20)
    SLOT(24) SLOT(28) SLOT(32) SLOT(36)
    SLOT(40) SLOT(44) SLOT(48) SLOT(52)
    SLOT(56) SLOT(60) SLOT(64) SLOT(68)
    SLOT(72) SLOT(76) SLOT(80) SLOT(84)
    SLOT(88) SLOT(92) SLOT(96) SLOT(100)
    SLOT(104) SLOT(108) SLOT(112) SLOT(116)
    SLOT(120) SLOT(124) SLOT(128) SLOT(132)
    SLOT(136) SLOT(140) SLOT(144) SLOT(148)
    SLOT(152) SLOT(156) SLOT(160) SLOT(164)
    SLOT(168) SLOT(172) SLOT(176) SLOT(180)
    SLOT(184) SLOT(188) SLOT(192) SLOT(196)
    SLOT(200) SLOT(204) SLOT(208) SLOT(212)
    SLOT(216) SLOT(220) SLOT(224) SLOT(228)
    SLOT(232) SLOT(236) SLOT(240) SLOT(244)
    SLOT(248) SLOT(252) SLOT(256) SLOT(260)
    SLOT(264) SLOT(268) SLOT(272) SLOT(276)
    SLOT(280) SLOT(284) SLOT(288) SLOT(292)
    SLOT(296) SLOT(300) SLOT(304) SLOT(308)
    SLOT(312) SLOT(316) SLOT(320) SLOT(324)
    SLOT(328) SLOT(332) SLOT(336) SLOT(340)
    SLOT(344) SLOT(348) SLOT(352) SLOT(356)
    SLOT(360) SLOT(364) SLOT(368) SLOT(372)
    SLOT(376) SLOT(380) SLOT(384) SLOT(388)
    SLOT(392) SLOT(396) SLOT(400) SLOT(404)
    SLOT(408) SLOT(412) SLOT(416) SLOT(420)
    SLOT(424) SLOT(428) SLOT(432) SLOT(436)
    SLOT(440) SLOT(444) SLOT(448) SLOT(452)
    SLOT(456) SLOT(460) SLOT(464) SLOT(468)
    SLOT(472) SLOT(476) SLOT(480) SLOT(484)
    SLOT(488) SLOT(492) SLOT(496) SLOT(500)
    SLOT(504) SLOT(508) SLOT(512) SLOT(516)
    SLOT(520) SLOT(524) SLOT(528) SLOT(532)
    SLOT(536) SLOT(540) SLOT(544) SLOT(548)
    SLOT(552) SLOT(556) SLOT(560) SLOT(564)
    SLOT(568) SLOT(572) SLOT(576) SLOT(580)
    SLOT(584) SLOT(588) SLOT(592) SLOT(596)
    SLOT(600) SLOT(604) SLOT(608) SLOT(612)
    SLOT(616) SLOT(620) SLOT(624) SLOT(628)
    SLOT(632) SLOT(636) SLOT(640) SLOT(644)
    SLOT(648) SLOT(652) SLOT(656) SLOT(660)
    SLOT(664) SLOT(668) SLOT(672) SLOT(676)
    SLOT(680) SLOT(684) SLOT(688) SLOT(692)
    SLOT(696) SLOT(700) SLOT(704) SLOT(708)
    SLOT(712) SLOT(716)
    virtual void call(u32, int, float);
    char pad40[0x20];
    Accesser* accesser;
};

#undef SLOT

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, u32, u32);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, u32, u32);
extern "C" const float lbl_27_rodata_1058;

extern "C" u32 fn_27_1386FC(Object* self, u32 state, int value, float amount) {
    Accesser* accesser = self->accesser;
    if (state == 1) {
        int workValue = value;
        if (value == -1) {
            Control* control = accesser->modules->control;
            control->call(13, 0, 0, -1);
            workValue =
                getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0x5a7d, 0);
        }

        Work* work = accesser->modules->work;
        work->setInt(workValue, 0x10000025);

        float workAmount = amount;
        if (lbl_27_rodata_1058 == amount) {
            workAmount =
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0xd9d, 0);
        }

        work = accesser->modules->work;
        work->setFloat(workAmount, 0x1100000c);

        Area* area = accesser->modules->area;
        area->on(3);

        Model* model = accesser->modules->model;
        model->set(true);

        work = accesser->modules->work;
        work->onFlag(0x12000012);
    } else {
        Work* work = accesser->modules->work;
        if (work->isFlag(0x12000012) == 1) {
            Area* area = accesser->modules->area;
            area->off(3);

            Model* model = accesser->modules->model;
            model->set(false);

            work = accesser->modules->work;
            work->offFlag(0x12000012);
        }
    }

    self->call(state, value, amount);
    return 1;
}
