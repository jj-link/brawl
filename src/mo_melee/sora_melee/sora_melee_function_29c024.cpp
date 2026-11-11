#include <types.h>
#pragma force_active on
extern "C" const f32 lbl_27_rodata_46DC;
class soNullable {
public:
 virtual void isNull();
 virtual void fn_27_2A052C();
 virtual void fn_27_281B1C();
 virtual void fn_27_29BFF4();
 virtual void fn_27_29BFC4();
 virtual void fn_27_289454();
 virtual void fn_27_29C134();
 virtual void fn_27_29C024();
 virtual void fn_27_28A1C4();
 virtual void fn_27_28A4F4();
 virtual void fn_27_289518();
 virtual void fn_27_29C584();
 virtual f32 fn_27_28903C(u32);
 virtual void fn_27_287730();
 virtual void fn_27_28B33C();
 virtual void fn_27_28BBA0();
 virtual void fn_27_28BDA8();
 virtual void fn_27_28C004();
 virtual void fn_27_2905E8();
 virtual void fn_27_28C0E0();
 virtual void fn_27_28871C();
 virtual s32 fn_27_2886CC();
};
struct Vec { f32 x,y,z; };
class Object_vptr_0 {
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
 virtual void slot10(s32, Vec*, Vec*);
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
};
struct MidObj { char pad[8]; soNullable* m_08; char pad2[0x54]; Object_vptr_0* m_60; soNullable* m_64; };
struct InnerObj { char pad[0xd8]; MidObj* m_d8; };
struct ArgObj { char pad[0x60]; InnerObj* m_60; };
inline void call(Object_vptr_0* p, Vec a, Vec b) { p->slot10(0, &a, &b); }
extern "C" void fn_27_29C024(void*, ArgObj* arg) {
 if (arg->m_60->m_d8->m_08->fn_27_2886CC() == 3) {
  u32 base = 0x11000000;
  soNullable* c = arg->m_60->m_d8->m_64;
  f32 v8 = c->fn_27_28903C(base + 8);
  f32 v7 = c->fn_27_28903C(base + 7);
  Vec v = {v7, v8, lbl_27_rodata_46DC};
  call(arg->m_60->m_d8->m_60, v, v);
 }
}