#include <types.h>
#pragma force_active on
extern "C" float lbl_27_rodata_65B8;
struct Vec3 { float x, y, z; };
class soNullable {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2();
 virtual void slot3(s32, s32, void*); virtual void slot4(); virtual void slot5();
 virtual void slot6(s32); virtual void slot7(s32); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(void*); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(Vec3*,s16*);
 virtual void slot18(Vec3*,s16*); virtual void slot19();
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
 virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28();
 virtual void fn_27_7AB50(); virtual void fn_27_7B2EC(); virtual void fn_27_7AB10();
 virtual void fn_27_7AD2C(); virtual void fn_27_7AEDC(); virtual s32 fn_27_7B22C(); virtual s32 fn_27_7AC38();
};
static inline void* getObj(u8* self,u32 off) {
 return *(void**)(*(u8**)(*(u8**)(self+0x60)+0xd8)+off);
}
extern "C" s32 fn_27_30F064(u8* self, f32* a, f32* b) {
 Vec3 v1; Vec3 v2; s16 s1[2]; s16 s2[2];
 ((soNullable*)getObj(self,0xc))->slot11(a);
 ((soNullable*)getObj(self,0xc))->slot19();
 s32 c = ((Class_90D8*)getObj(self,0xbc))->fn_27_7AC38();
 ((soNullable*)getObj(self,0x18))->slot3(c,1,*(void**)(self+0x60));
 ((soNullable*)getObj(self,0x18))->slot6(c);
 u8* p = *(u8**)(*(u8**)(self+0x60)+0xd8);
 Class_90D8* o4 = (Class_90D8*)*(void**)(p+0xbc);
 soNullable* o28 = (soNullable*)*(void**)(p+0x18);
 o28->slot7(o4->fn_27_7B22C());
 if (lbl_27_rodata_65B8 != a[0] || lbl_27_rodata_65B8 != a[1]) {
  float x, y; y = a[1]; x = a[0];
  s1[0]=1; v1.x=x; v1.y=y; v1.z=lbl_27_rodata_65B8;
  ((soNullable*)getObj(self,0x7c))->slot17(&v1,s1);
 }
 if (lbl_27_rodata_65B8 != b[0] || lbl_27_rodata_65B8 != b[1]) {
  float x, y; y = b[1]; x = b[0];
  s2[0]=1; v2.x=x; v2.y=y; v2.z=lbl_27_rodata_65B8;
  ((soNullable*)getObj(self,0x7c))->slot18(&v2,s2);
 }
 return 0;
}