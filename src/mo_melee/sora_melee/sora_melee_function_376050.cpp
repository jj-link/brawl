#include <types.h>
#include <math.h>
#include <mt/mt_vector.h>
#pragma force_active on
struct Vec { float x,y,z; };
struct Posture {
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual Vec slot14(int);
 virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18();
 virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual float slot22();
};
struct Energy {
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void* slot6(int);
};

struct Speed {
 virtual void slot0(); virtual void slot1(); virtual Vec2f slot2();
};
struct Pad { int a,b; };
struct Model : Pad {
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(int, Vec*, Vec*, Vec*);
};
struct Modules { char pad0[4]; Model* model; char pad8[4]; Posture* posture; char pad10[0x6c]; Energy* energy; };
struct Actor { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Actor* actor; };
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern "C" float lbl_27_rodata_7BF4;
extern "C" void fn_27_376050(Object* object) {
 Vec scale;
 scale.x = scale.y = scale.z = object->actor->modules->posture->slot22();
 Vec position;
 Vec rotation;
 rotation = object->actor->modules->posture->slot4();
 position = object->actor->modules->posture->slot14(0);
 Speed* speed = (Speed*)__dynamic_cast(object->actor->modules->energy->slot6(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
 Vec2f v;
 Vec2f::copy(v, speed->slot2());
 float x = v.m_x;
 float y = v.m_y;
 position.z = lbl_27_rodata_7BF4 * (float)atan2(y, x);
 object->actor->modules->model->slot22(0, &scale, &position, &rotation);
}