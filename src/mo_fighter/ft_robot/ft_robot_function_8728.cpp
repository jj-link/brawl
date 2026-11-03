#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct FighterBase {
    unsigned char padding[0x3C];
};

#define V(n) virtual void slot##n();
struct Fighter : FighterBase {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138) V(139)
    V(140) V(141) V(142) V(143) V(144) V(145) V(146) V(147) V(148) V(149)
    V(150) V(151) V(152) V(153) V(154) V(155) V(156) V(157) V(158) V(159)
    V(160) V(161) V(162) V(163) V(164) V(165) V(166) V(167) V(168) V(169)
    V(170) V(171) V(172) V(173) V(174) V(175) V(176) V(177) V(178) V(179)
    V(180) V(181) V(182) V(183) V(184)
    virtual void* call185();
};
#undef V

struct PostureModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual float getLr();
};

struct ResourceAccesser {
    virtual void slot08();
    virtual void slot0C();
    virtual int getId();
};

struct ResourceModule {
    virtual void slot08();
    virtual void slot0C();
    virtual ResourceAccesser* getAccesser();
};

struct OwnerAccesser {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual int slot30();
};

struct OwnerBase {
    unsigned int padding[2];
};

struct OwnerModule : OwnerBase {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual OwnerAccesser* getAccesser();
};

struct SlotModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int slot14();
};

struct ModuleTable {
    OwnerModule* owner;
    unsigned char padding04[8];
    PostureModule* posture;
    unsigned char padding10[4];
    SlotModule* slot;
    ResourceModule* resource;
};

struct ObjectData {
    unsigned char padding[0x28];
    unsigned int taskId;
};

struct soModuleAccesser {
    unsigned char padding00[8];
    ObjectData* objectData;
    unsigned char padding0C[0xCC];
    ModuleTable* modules;
};

extern "C" {
extern const char lbl_120_data_242C[], lbl_120_data_2CA8[];
extern const float lbl_120_rodata_8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1119B8(void*);
Vec3f* fn_120_8718(Vec3f*, float, float, float);
void fn_120_15CA0(void*, unsigned int, int, int, float, const Vec3f*, int);
}

extern "C" bool fn_120_8728(void* request, soModuleAccesser* accesser) {
    Fighter* fighter;
    ModuleTable* modules;
    PostureModule* posture;
    int resId;
    Vec3f* pos;
    int slotId;
    ResourceModule* resource;
    OwnerModule* owner;
    unsigned int taskId;
    Vec3f position;

    fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->objectData, 0x3C, lbl_120_data_242C, lbl_120_data_2CA8, 1));
    fn_27_1119B8(fighter->call185());
    modules = accesser->modules;
    posture = modules->posture;
    resource = modules->resource;
    owner = modules->owner;
    taskId = accesser->objectData->taskId;
    slotId = modules->slot->slot14();
    pos = fn_120_8718(&position, lbl_120_rodata_8, lbl_120_rodata_8, lbl_120_rodata_8);
    float dir = posture->getLr();
    resId = resource->getAccesser()->getId();
    int ownerId = owner->getAccesser()->slot30();
    fn_120_15CA0(request, taskId, ownerId, resId, dir, pos, slotId);
    return true;
}
