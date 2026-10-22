#pragma force_active on
#pragma opt_propagation off

typedef float f32;
struct Constants { float x[21]; };
extern "C" const Constants lbl_62_rodata_1B0;
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);
struct Vec2 { float x, y; Vec2(float a,float b):x(a),y(b){} };
struct soAreaData {
    signed char shape, group;
    unsigned short mask;
    int a,b,node;
    Vec2 offset,range;
};
template<class T> struct soSet { T* p; int count; };
struct ykAreaData { char data[12]; };
class Yakumono;
class stTrigger { public: void setObserveYakumono(Yakumono*); };
class Gimmick { public: enum AreaKind { Dummy=0 }; };
class stTriggerMng { public: stTrigger* createTrigger(Gimmick::AreaKind,int); };
extern "C" stTriggerMng* g_stTriggerMng;
class grYakumono {
public:
    char pad[0x14c]; Yakumono* y; char pad2[0x4c]; stTrigger* trigger;
    soAreaData area; soSet<soAreaData> set; ykAreaData data;
    void setAreaGimmick(soAreaData*,soSet<soAreaData>*,ykAreaData*,bool);
};
extern "C" void fn_62_FEC0(grYakumono* self) {
    const Constants* data=&lbl_62_rodata_1B0;
    gfMemFill__FPvUcUl(&self->data,0,12);
    self->area.shape=0;
    self->area.group=21;
    self->area.a=0;
    self->area.b=0;
    self->area.mask=1;
    self->area.node=12;
    self->area.offset.x=data->x[14];
    self->area.offset.y=data->x[0];
    self->area.range.x=data->x[15];
    self->area.range.y=data->x[15];
    self->setAreaGimmick(&self->area, &self->set, &self->data, true);
    stTrigger* t=g_stTriggerMng->createTrigger((Gimmick::AreaKind)47,-1);
    self->trigger=t;
    t->setObserveYakumono(self->y);
}
