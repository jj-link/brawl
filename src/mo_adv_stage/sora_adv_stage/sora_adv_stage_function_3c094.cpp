#pragma force_active on

struct Vec3f {
    float x, y, z;
    Vec3f() {}
};

struct Data {
    char pad[0x18];
    float x, y, z, w, px, py;
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

struct grYakumono {
    char pad0[0xBC];
    Data* baseData;
    char padC0[0x8C];
    void* yakumono;
    Data* data;
    soAreaData area;
    soSet<soAreaData> areaSet;
    ykAreaData areaData;

    void setAreaGimmick(soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
};

extern "C" {
void startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(void*, void*, unsigned long, int);
void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void*, int, int);
void setObserveYakumono__9stTriggerFP8Yakumono(void*, void*);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern void* g_stTriggerMng;
extern float lbl_40_rodata_838;
}

extern "C" void fn_40_3C094(grYakumono* self, void* arch, unsigned long p, int layer) {
    startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(self, arch, p, layer);
    self->data = self->baseData;
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 15);
    setCalcuCallbackRoot__9grGimmickFUl(self, 3);

    self->area.shape = 0;
    self->area.group = 21;
    self->area.a = 0;
    self->area.b = 0;
    self->area.flags = 0;
    self->area.node = 0;
    self->area.x = self->data->x;
    self->area.y = self->data->y;
    self->area.z = self->data->z;
    self->area.w = self->data->w;

    self->setAreaGimmick(&self->area, &self->areaSet, &self->areaData, false);
    setObserveYakumono__9stTriggerFP8Yakumono(
        createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(g_stTriggerMng, 45, -1),
        self->yakumono);

    Vec3f pos;
    Data* data = self->data;
    float z, x, y;
    z = lbl_40_rodata_838;
    y = data->py;
    x = data->px;
    pos.x = x;
    pos.y = y;
    pos.z = z;
    setPos__9grGimmickFP5Vec3f(self, &pos);
}
