#include <mt/mt_vector.h>
#pragma force_active on
#pragma inline all
extern "C" const float lbl_27_rodata_450;
#define V10(n) virtual void v##n##0(); virtual void v##n##1(); virtual void v##n##2(); virtual void v##n##3(); virtual void v##n##4(); virtual void v##n##5(); virtual void v##n##6(); virtual void v##n##7(); virtual void v##n##8(); virtual void v##n##9();
union Vec2 { struct { float x, y; }; unsigned int words[2]; Vec2() {} };
class soNullable { public:
 virtual void isNull(); virtual void fn_27_31270(); virtual int fn_27_31C88();
 char pad[0x10]; Vec2f pos;
};
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); };
struct OtherBase { char pad[8]; };
struct Other:OtherBase {
 V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
 virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85();
 virtual Vec2 get(int);
};
extern "C" Vec2f fn_27_312B0(soNullable*,const Vec2f*,float);
inline Vec2f center(soNullable* self, Vec2 a, float scale) {
 Vec2f ret; Vec2f::copy(ret, fn_27_312B0(self,(Vec2f*)&a,scale));
 Vec2f sum; Vec2f::copy(sum, self->pos + ret);
 return sum;
}
extern "C" Vec2f fn_27_32460(soNullable* self,Other* other,int idx,float scale) {
 if (!self->fn_27_31C88()) return Vec2f(lbl_27_rodata_450,lbl_27_rodata_450);
 Vec2 a=other->get(idx);
 Vec2f sum; Vec2f::copy(sum,center(self,a,scale));
 Vec2f result; Vec2f::copy(result,sum-*(Vec2f*)&a);
 return result;
}