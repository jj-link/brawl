#include <math.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_75AC;
extern "C" const float lbl_27_rodata_75B8;
struct Vec { float x, y, z; };
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(void*);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual float slot9();
 virtual void slot10(float);
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15(Vec*, int);
};
struct Modules { char pad[8]; soNullable* a; soNullable* b; };
struct Object { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x60]; Object* object; };
extern "C" void fn_27_328378(Self* self, void* arg, Vec* v, int flag, float scale) {
 Object* obj = self->object;
 obj->modules->b->slot5(arg);
 if (flag) obj->modules->a->slot10(lbl_27_rodata_75AC);
 if (lbl_27_rodata_75AC == scale) scale = obj->modules->b->slot9();
 float y = v->y;
 float x = v->x;
 float angle = scale * (float)atan2(x, y);
 Vec result;
 result.x = lbl_27_rodata_75B8 * angle;
 result.y = lbl_27_rodata_75AC;
 result.z = lbl_27_rodata_75AC;
 obj->modules->b->slot15(&result, 0);
}