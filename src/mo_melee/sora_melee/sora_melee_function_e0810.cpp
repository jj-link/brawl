#pragma force_active on
#include <so/so_array.h>
struct Element {
 unsigned int m0;
 short m4,m6;
 float m8,mc;
 unsigned int m10,m14,m18,m1c,m20,m24,m28;
 unsigned short m2c,m2e;
 unsigned char m30,m31,m32,m33,m34,m35,m36,m37,m38,m39,m3a;
 unsigned int m3c,m40,m44,m48;
 float m4c;
 unsigned int m50,m54,m58,m5c;
 float m60,m64,m68;
 unsigned int m6c,m70,m74,m78;
 float m7c,m80;
 unsigned int m84,m88,m8c;
 float m90,m94,m98,m9c,ma0,ma4,ma8,mac;
 unsigned char mb0,mb1,mb2,mb3,mb4;
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual int slot13(); virtual bool slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual Element* slot26(int);
 virtual int slot27(); virtual int slot28(); virtual void slot29(int);
};
extern "C" void fn_27_E0810(Object_vptr_0* self, const Element* value) {
 int pos = soArrayVectorCalculator::push(
  *(soArrayVectorCalcInterface*)((char*)self + 4),
  self->slot14(), self->slot13(), self->slot27(), self->slot28());
 Element* d = self->slot26(pos);
 *d = *value;
 self->slot29(self->slot3() + 1);
}