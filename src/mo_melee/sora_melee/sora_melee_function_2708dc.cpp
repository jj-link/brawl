#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Data {
    char pad[0x18];
    float x, y, z, w;
};

struct soAreaData {
    unsigned char shape, group;
    unsigned short flags;
    int a, b, node;
    float x, y, z, w;
};

template<class T>
struct soSet {
    char pad[8];
};

struct ykAreaData {
    char pad[12];
};

struct Yakumono;

#define SLOT(n) virtual void slot##n();

struct Base {
    char pad[0x3C];

    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
    SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70) SLOT(71)
    SLOT(72) SLOT(73) SLOT(74) SLOT(75)
    SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80)
    virtual Data* getData();
};

#undef SLOT

struct grYakumono : Base {
    char pad40[0x10C];
    Yakumono* yakumono;
    Data* data;
    soAreaData area;
    soSet<soAreaData> areaSet;
    ykAreaData areaData;

    void setAreaGimmick(
        soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
};

extern "C" {
void startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(
    void*, void*, unsigned long, int);
void updateG3dProcCalcWorld__6GroundFv(void*);
void getNodePosition__6GroundFP5Vec3fUlUl(
    void*, Vec3f*, unsigned long, unsigned long);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(
    void*, int, int);
void setObserveYakumono__9stTriggerFP8Yakumono(void*, Yakumono*);
extern void* g_stTriggerMng;
}

extern "C" void fn_27_2708DC(
    grYakumono* self, void* arch, unsigned long p, int layer)
{
    Vec3f pos;

    startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(
        self, arch, p, layer);
    self->data = self->getData();
    updateG3dProcCalcWorld__6GroundFv(self);
    getNodePosition__6GroundFP5Vec3fUlUl(self, &pos, 0, 0);
    setPos__9grGimmickFP5Vec3f(self, &pos);
    gfMemFill__FPvUcUl(&self->areaData, 0, 12);

    self->area.shape = 0;
    self->area.group = 21;
    self->area.a = 0;
    self->area.b = 0;
    self->area.flags = 1;
    self->area.node = 0;
    self->area.x = self->data->x;
    self->area.y = self->data->y;
    self->area.z = self->data->z;
    self->area.w = self->data->w;

    self->setAreaGimmick(
        &self->area, &self->areaSet, &self->areaData, false);
    setObserveYakumono__9stTriggerFP8Yakumono(
        createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(
            g_stTriggerMng, 30, -1),
        self->yakumono);
}
