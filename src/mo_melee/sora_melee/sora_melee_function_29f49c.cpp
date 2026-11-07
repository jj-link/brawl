#include <mt/mt_vector.h>
#pragma force_active on
extern const float lbl_27_rodata_46C8[];
class PositionModule {
public:
 virtual void isNull();
 virtual void fn_27_2A09AC();
 virtual void fn_27_281B1C();
 virtual void fn_27_2839BC();
 virtual Vec3f fn_27_284EA0();
 virtual void fn_27_289454(const Vec3f&);
 virtual void fn_27_289FAC();
 virtual void fn_27_28A178();
 virtual void fn_27_28A1C4();
 virtual float fn_27_28A4F4();
 virtual void fn_27_289518();
 virtual void fn_27_289560();
 virtual void fn_27_28903C();
 virtual void fn_27_287730();
 virtual Vec3f fn_27_28B33C(int);
 virtual void fn_27_28BBA0(const Vec3f&, int);
 virtual void fn_27_28BDA8();
 virtual void fn_27_28C004();
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual int slot17(int);
};
struct Inner { char pad[0xc]; PositionModule* object; char pad2[0x54]; Object_vptr_0* flags; };
struct Middle { char pad[0xd8]; Inner* inner; };
struct Self { char pad[0x60]; Middle* middle; };
extern "C" int fn_27_29F49C(void*, Self* self) {
 const float* k = lbl_27_rodata_46C8;
 Vec3f pos = self->middle->inner->object->fn_27_28B33C(0);
 pos.m_x -= k[51];
 pos.m_y += k[29] * self->middle->inner->object->fn_27_28A4F4();
 if (self->middle->inner->flags->slot17(0x12000000)) {
  pos.m_x -= k[52];
  Vec3f rot = self->middle->inner->object->fn_27_284EA0();
  rot.m_x += k[0];
  rot.m_z += k[1];
  self->middle->inner->object->fn_27_289454(rot);
 }
 self->middle->inner->object->fn_27_28BBA0(pos, 0);
 return 0;
}