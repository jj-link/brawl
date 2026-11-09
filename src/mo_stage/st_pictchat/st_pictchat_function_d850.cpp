#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct soAreaData {
    u8 a, b;
    u16 c;
    u32 d, e, f;
    float x, y, z, w;
};

template <class T> struct soSet;

struct ykAreaData {
    u32 data[3];
};

struct grYakumono {
    void setAreaGimmick(soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
};

struct StageData {
    u8 pad[0x20];
    float x, y, z, w;
};

#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)

struct ObjectBase {
    u8 pad0[0x3c];

    V64(a) V16(b) V1(c)
    virtual StageData* getData();
    V16(d) V8(e) V4(f) V2(g) V1(h)
    virtual void getPos(Vec3f*);
};

struct Object : ObjectBase {
    u8 pad40[0x10c];
    void* yakumono;
    StageData* data;
    u8 pad154[0x14];
    soAreaData area;
    u8 set[8];
    ykAreaData yk;
    u8 pad19c[0x1c];
    u8 state;
};

extern "C" void* memset(void*, int, unsigned long);
extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void*, int, int);
extern "C" void setObserveYakumono__9stTriggerFP8Yakumono(void*, void*);
extern "C" void* g_stTriggerMng;

extern "C" void fn_73_D850(Object* self) {
    if (self->state == 1) {
        Vec3f pos;
        self->getPos(&pos);
        setPos__9grGimmickFP5Vec3f(self, &pos);
    } else {
        self->data = self->getData();
        memset(&self->yk, 0, 12);
        self->area.a = 0;
        self->area.b = 0x15;
        self->area.d = 0;
        self->area.e = 0;
        self->area.c = 1;
        self->area.f = 0;
        self->area.x = self->data->x;
        self->area.y = self->data->y - 1.0f;
        self->area.z = self->data->z;
        self->area.w = 1.0f + self->data->w;
        ((grYakumono*)self)->setAreaGimmick(
            &self->area,
            (soSet<soAreaData>*)self->set,
            &self->yk,
            false
        );
        void* trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(
            g_stTriggerMng, 0x23, -1
        );
        setObserveYakumono__9stTriggerFP8Yakumono(trigger, self->yakumono);
        self->state = 1;
    }
}
