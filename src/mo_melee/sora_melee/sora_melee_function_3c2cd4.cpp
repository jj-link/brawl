#include <mt/mt_vector.h>
#pragma force_active on
struct Flag { short value; Flag(short v): value(v) {} };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, Vec2f*, Vec3f*, void*);
 virtual void* slot6(int);
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual Vec2f slot13(Flag);
};
struct Inner { char pad[0x7c]; Object_vptr_0* energy; };
struct Outer { char pad[0xd8]; Inner* inner; };
extern "C" {
 void* __dynamic_cast(void*, long, const void*, const void*, short);
 float fn_27_192278(void*, unsigned long);
 extern char lbl_27_data_2E5F8[], lbl_27_data_2E430[], lbl_27_data_CDF8[];
 extern const float lbl_27_rodata_8084, lbl_27_rodata_808C;
}
extern "C" void fn_27_3C2CD4(void*, Outer* self) {
 Object_vptr_0* stop=(Object_vptr_0*)__dynamic_cast(self->inner->energy->slot6(3),0,lbl_27_data_2E5F8,lbl_27_data_CDF8,1);
 Object_vptr_0* grav=(Object_vptr_0*)__dynamic_cast(self->inner->energy->slot6(1),0,lbl_27_data_2E430,lbl_27_data_CDF8,1);
 Vec2f v;
 Vec2f::copy(v,self->inner->energy->slot13(Flag(1)));
 stop->slot5(6,&Vec2f(v.m_x,lbl_27_rodata_8084),&Vec3f(lbl_27_rodata_8084,lbl_27_rodata_8084,lbl_27_rodata_8084),self);
 *(Vec2f*)((char*)stop+0x10)=Vec2f(lbl_27_rodata_8084,lbl_27_rodata_8084);
 *(Vec2f*)((char*)stop+0x18)=Vec2f(lbl_27_rodata_8084,lbl_27_rodata_8084);
 *(Vec2f*)((char*)stop+0x20)=Vec2f(lbl_27_rodata_8084,lbl_27_rodata_8084);
 *(Vec2f*)((char*)stop+0x28)=Vec2f(lbl_27_rodata_808C,lbl_27_rodata_808C);
 ((unsigned char*)stop)[5]|=0x80;
 grav->slot5(0,&Vec2f(lbl_27_rodata_8084,v.m_y),&Vec3f(lbl_27_rodata_8084,lbl_27_rodata_8084,lbl_27_rodata_8084),self);
 *(float*)((char*)grav+0x10)=-fn_27_192278(self,0xfa0);
 *(float*)((char*)grav+0x1c)=fn_27_192278(self,0xfa1);
 *(float*)((char*)grav+0x14)=fn_27_192278(self,0xfa1);
 ((unsigned char*)grav)[5]|=0x80;
}