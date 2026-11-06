#include <so/so_module_accesser.h>
#include <so/so_array.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>
#pragma force_active on

#pragma pack(push, 4)
union VectorResult { unsigned long long bits; Vec2f v; };
#pragma pack(pop)

class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual unsigned long long slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
};
class KineticView : public soNullable {
public:
virtual void activate();
virtual void deactivate();
virtual void addEnergy();
virtual void eraseEnergy();
virtual void eraseEnergyAll();
virtual Object_vptr_0* getEnergy(int);
virtual void isContain();
virtual void updateEnergy();
virtual void clearSpeedAll();
virtual void suspendEnergyAll();
virtual void resumeEnergyAll();
virtual void unableEnergyAll();
virtual unsigned long long getSumSpeed(const unsigned short&);
};
struct GroundBase { char padding[8]; };
class GroundView : public GroundBase {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual unsigned long long getAttachMovementSpeed(unsigned int);
};
struct Record {
Vec2f pos;
float facing;
union {
struct { unsigned int kind:5; unsigned int rest:27; };
struct { unsigned char first; unsigned char flag; unsigned short tail; };
};
};
extern "C" {
extern const float lbl_113_rodata_C;
extern const float lbl_113_rodata_10;
float fn_113_BF74(const Vec2f*);
unsigned long long fn_113_BFB0(const Vec2f*,const Vec2f*);
void fn_113_BF8C(const Vec2f*,const Vec2f*,Vec2f*);
int fn_113_100F0(soModuleAccesser*,float);
void fn_113_10A34(unsigned char*,soModuleAccesser*);
void fn_113_B7F0(Vec2f*,const Vec3f*);
void fn_113_BFE4(Record*,short);
void fn_113_246E0(void*,void*,soModuleAccesser*);
}
class RecordArray {
public:
virtual bool isNull() const;
virtual Record& at(int);
virtual const Record& at(int) const;
virtual int size() const;
virtual bool isEmpty() const;
virtual ~RecordArray();
virtual void shift();
virtual void pop();
virtual void clear();
virtual void unshift(const Record&);
virtual void push(const Record&);
virtual void insert(int,const Record&);
virtual void erase(int);
virtual int capacity() const;
virtual bool isFull() const;
};
struct Owner {
char pad[0x60];
soModuleAccesser* accesser;
char pad64[0x1fe8c-0x64];
RecordArray recordArray;
};
inline soArray<Record>* records(Owner* self) { return reinterpret_cast<soArray<Record>*>((char*)self+0x1fe8c); }
inline KineticView* kinetic(Owner* self) { return reinterpret_cast<KineticView*>(self->accesser->m_enumerationStart->m_kineticModule); }

extern "C" void fn_113_BCB0(Owner* self) {
if (self->recordArray.isFull() == 1U) self->recordArray.pop();
VectorResult speed;
VectorResult sum;
VectorResult a;
a.bits = kinetic(self)->getEnergy(6)->slot2();
speed = a;
unsigned short mask = 7;
VectorResult b;
b.bits = kinetic(self)->getSumSpeed(mask);
sum = b;
if (lbl_113_rodata_C != fn_113_BF74(&speed.v)) {
VectorResult diff;
VectorResult ground;
ground.bits = reinterpret_cast<GroundView*>(self->accesser->m_enumerationStart->m_groundModule)->getAttachMovementSpeed(0);
diff.bits = fn_113_BFB0(&speed.v,&ground.v);
fn_113_BF8C(&sum.v,&diff.v,&sum.v);
}
float sq = fn_113_BF74(&sum.v);
float length;
if ((float)(double)nw4r::math::FAbs(sq) <= lbl_113_rodata_10) length = lbl_113_rodata_C;
else length = sq * rsqrtf(sq);
int kind = fn_113_100F0(self->accesser,length);
unsigned char flag = 0;
fn_113_10A34(&flag,self->accesser);
float facing = self->accesser->m_enumerationStart->m_postureModule->getLr();
Vec3f pos = self->accesser->getPostureModule().getPos();
Vec2f xy;
fn_113_B7F0(&xy,&pos);
Record record;
Vec2f::copy(record.pos,xy);
record.facing = facing;
record.kind = kind;
record.flag = flag;
self->recordArray.unshift(record);
fn_113_BFE4(&record,-1);
if (lbl_113_rodata_C != fn_113_BF74(&speed.v)) {
int count = self->recordArray.size();
for(int i=1;i<count;++i) {
Vec2f* v = &self->recordArray.at(i).pos;
fn_113_BF8C(v,&speed.v,v);
}
}
fn_113_246E0((char*)self+0x1fd08,&self->recordArray,self->accesser);
}
