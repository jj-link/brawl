#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_vector.h>
#pragma force_active on
class soNullable {
public:
virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void* slot6(int); virtual void slot7(); virtual void slot8(); virtual float slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual bool slot17(unsigned long); virtual void slot18(unsigned long); virtual void slot19(); virtual void slot20(); virtual void slot21(int,void*);
};
class Controller {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual float slot18();
};
struct Modules { char pad0[0xc]; soNullable* posture; char pad1[0x4c]; Controller* controller; char padWork[4]; soNullable* work; char pad2[0x14]; soNullable* kinetic; };
struct Fighter { char pad[0xd8]; Modules* modules; };
struct Energy {
char pad[5]; signed char flags; char pad2[2]; float x,y; char pad3[8]; float x2,y2,x3,y3,x4,y4;
void set(float cosine, float speed, float facing) { Vec2f zero(lblzero(), lblzero()); float product = cosine * speed; Vec2f v(product * facing, zero.m_y * speed); x=v.m_x; y=v.m_y; x4=v.m_x; y4=v.m_y; x2=v.m_x; y2=v.m_y; x3=zero.m_x; y3=zero.m_y; flags |= 0x80; }
static float lblzero();
};
struct Gravity { char pad[12]; float y; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(void*, unsigned long);
double cos(double); double sin(double);
extern char lbl_27_data_13690[]; extern char lbl_27_data_2E430[]; extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_75CC; extern const float lbl_27_rodata_75D0;
}
inline float Energy::lblzero() {return lbl_27_rodata_75CC;}
extern "C" void fn_27_32923C(Fighter* self) {
soNullable* work=self->modules->work;
if (work->slot17(0x22000012) && !work->slot17(0x22000013)) {
soNullable* kinetic=self->modules->kinetic;
Energy* energy=(Energy*)__dynamic_cast(kinetic->slot6(3),0,lbl_27_data_13690,lbl_27_data_CDF8,1);
Gravity* gravity=(Gravity*)__dynamic_cast(kinetic->slot6(1),0,lbl_27_data_2E430,lbl_27_data_CDF8,1);
kinetic->slot21(0,self);
((Energy*)kinetic->slot6(2))->flags &= ~0x80;
float stick=self->modules->controller->slot18();
float max;
float amount=nw4r::ut::Abs(stick);
max=fn_27_192278(self,0xfa1);
if(amount>max) amount=max;
float min=fn_27_192278(self,0xfa0);
amount-=min;
if(amount<lbl_27_rodata_75CC) amount=lbl_27_rodata_75CC;
if(stick<lbl_27_rodata_75CC) amount=-amount;
float range=max-min;
float angle=lbl_27_rodata_75D0*((amount*fn_27_192278(self,0xfa2))/range);
float facing=self->modules->posture->slot9();
float speed=fn_27_192278(self,0xfa3);
energy->set((float)cos(angle), speed, facing);
gravity->y=speed*(float)sin(angle);
work->slot18(0x22000013);
}
}