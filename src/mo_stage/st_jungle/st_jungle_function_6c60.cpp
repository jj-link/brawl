#pragma force_active on
#include <so/so_array.h>
struct Element {
 float m0,m4,m8,mc;
 unsigned int m10,m14,m18,m1c,m20,m24,m28;
 unsigned short m2c,m2e;
 unsigned char m30,m31,m32,m33,m34,m35,m36,m37,m38,m39,m3a;
 unsigned int m3c,m40,m44,m48;
 float m4c;
 unsigned int m50,m54,m58,m5c;
 float m60,m64,m68;
 unsigned int m6c,m70,m74,m78;
 float m7c;
 unsigned int m80,m84,m88,m8c,m90;
 float m94;
 unsigned int m98;
 unsigned char m9c;
};
class Array {
public:
 virtual void v08(); virtual void v0c(); virtual void v10(); virtual int size();
 virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
 virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
 virtual void v38(); virtual int v3c(); virtual bool v40(); virtual void v44();
 virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54();
 virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64();
 virtual void v68(); virtual void v6c(); virtual Element* at(int);
 virtual int v74(); virtual int v78(); virtual void setSize(int);
};
extern "C" void fn_51_6C60(Array* self, const Element* value) {
 int pos = soArrayVectorCalculator::push(
  *(soArrayVectorCalcInterface*)((char*)self + 4),
  self->v40(), self->v3c(), self->v74(), self->v78());
 Element* d = self->at(pos);
 d->m0 = value->m0;
 d->m4 = value->m4;
 d->m8 = value->m8;
 d->mc = value->mc;
 d->m10 = value->m10;
 d->m14 = value->m14;
 d->m18 = value->m18;
 d->m1c = value->m1c;
 d->m20 = value->m20;
 d->m24 = value->m24;
 d->m28 = value->m28;
 d->m2c = value->m2c;
 d->m2e = value->m2e;
 d->m30 = value->m30;
 d->m31 = value->m31;
 d->m32 = value->m32;
 d->m33 = value->m33;
 d->m34 = value->m34;
 d->m35 = value->m35;
 d->m36 = value->m36;
 d->m37 = value->m37;
 d->m38 = value->m38;
 d->m39 = value->m39;
 d->m3a = value->m3a;
 d->m3c = value->m3c;
 d->m40 = value->m40;
 d->m44 = value->m44;
 d->m48 = value->m48;
 d->m4c = value->m4c;
 d->m50 = value->m50;
 d->m54 = value->m54;
 d->m58 = value->m58;
 d->m5c = value->m5c;
 d->m60 = value->m60;
 d->m64 = value->m64;
 d->m68 = value->m68;
 d->m6c = value->m6c;
 d->m70 = value->m70;
 d->m74 = value->m74;
 d->m78 = value->m78;
 unsigned int w80 = value->m80;
 d->m7c = value->m7c;
 unsigned int w84 = value->m84;
 d->m80 = w80;
 unsigned int w88 = value->m88;
 d->m84 = w84;
 unsigned int w8c = value->m8c;
 d->m88 = w88;
 unsigned int w90 = value->m90;
 d->m8c = w8c;
 float w94 = value->m94;
 d->m90 = w90;
 unsigned int w98 = value->m98;
 d->m94 = w94;
 unsigned char w9c = value->m9c;
 d->m98 = w98;
 d->m9c = w9c;
 self->setSize(self->size() + 1);
}