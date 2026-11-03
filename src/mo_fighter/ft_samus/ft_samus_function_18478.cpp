#include <so/so_value_accesser.h>
#pragma force_active on
typedef unsigned long long u64;
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Parameters { Vec2 p[4]; };
struct Kinetic {
 virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
 virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7();
 virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11();
 virtual void u12(); virtual u64 getSpeed(const short*);
};
struct Posture {
 virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
 virtual Vec3 getPos();
 virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8();
 virtual float getLr();
 virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13();
 virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17();
 virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21();
 virtual float getScale();
};
struct Modules { char pad[0xc]; Posture* posture; char pad1[0x6c]; Kinetic* kinetic; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Accesser* accesser; };
extern "C" {
void fn_27_13CC24(void*);
void fn_94_A82C(Parameters*);
void fn_27_13FE28(void*, const Vec3&, float, float, const Vec2&, const Parameters&, const Parameters&, int);
extern const float lbl_94_rodata_60;
extern const float lbl_94_rodata_64;
}
extern "C" void fn_94_18478(Object* object, void* output) {
 fn_27_13CC24(object);
 Accesser* accesser = object->accesser;
 Parameters b;
 fn_94_A82C(&b);
 b.p[0].x = lbl_94_rodata_60;
 b.p[1].x = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xbd6, 0);
 b.p[2].x = lbl_94_rodata_60;
 b.p[3].x = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xbd8, 0);
 b.p[0].y = lbl_94_rodata_60;
 b.p[1].y = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xbd1, 0);
 b.p[2].y = lbl_94_rodata_60;
 b.p[3].y = lbl_94_rodata_60;
 Parameters a;
 fn_94_A82C(&a);
 a.p[0].x = lbl_94_rodata_60;
 a.p[1].x = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xbbc, 0);
 a.p[2].x = lbl_94_rodata_60;
 a.p[3].x = lbl_94_rodata_64;
 a.p[0].y = lbl_94_rodata_60;
 a.p[1].y = lbl_94_rodata_60;
 a.p[2].y = lbl_94_rodata_60;
 a.p[3].y = lbl_94_rodata_60;
 short flag = -1;
 Kinetic* kinetic = accesser->modules->kinetic;
 Vec2 speed;
 *(u64*)&speed = kinetic->getSpeed(&flag);
 Posture* posture = accesser->modules->posture;
 fn_27_13FE28(output, posture->getPos(), posture->getScale(), posture->getLr(), speed, a, b, 0xf60003);
}