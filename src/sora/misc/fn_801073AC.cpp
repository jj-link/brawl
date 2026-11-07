#include <mu/menu.h>
#pragma force_active on
struct Object {
 char pad0[0x48]; unsigned char flags; char pad49[3]; unsigned int frame; unsigned int value;
 unsigned char a,b,c,d; char pad58[8]; void* p60; unsigned char c64,c65,c66,c67,f68,f69,f6a,f6b;
 void* p6c; char pad70[12]; unsigned char entries[99]; char padDF; int count; int index; char* values[7]; void* holder; char pad108[4]; int field10c;
};
extern "C" {
void fn_800E244C(void*);
void fn_800E4ED0(char**, int);
void fn_80108544(void*);
void fn_80108E5C(void*);
void fn_8010BDCC(void*);
void fn_8010C6C8(void*, unsigned int);
void fn_8010C0FC(void*, unsigned int);
void fn_8010C060(void*);
void fn_8010C3D4(void*);
void fn_8010CCE0(void*, int, char*, int, float);
void fn_8010CA94(void*, int, void*);
void fn_8010CC80(void*);
void fn_8010CCA0(void*, int);
void fn_80108858(void*, int, int);
void fn_80108798(void*, int);
}
extern "C" void fn_801073AC(Object* self) {
 Object* cursor = self;
 for (int i=0;i<7;i++,cursor=(Object*)((char*)cursor+4)) {
  if (cursor->values[0]) fn_800E244C(cursor->values[0]);
 }
 fn_800E4ED0(self->values,7);
 if (self->p60) fn_80108544(self->p60);
 if (self->p60) fn_80108E5C(self->p6c);
 if (self->holder) fn_8010BDCC(self->holder);
 if ((self->flags >> 7) & 1) if (self->holder) fn_8010C6C8(self->holder,self->frame);
 unsigned int value=self->value;
 if (value>999999999) value=999999999;
 if (self->holder) fn_8010C0FC(self->holder,value);
 if ((self->flags >> 6) & 1) if (self->holder) fn_8010C060(self->holder);
 if (self->field10c>=0) if (self->holder) fn_8010C3D4(self->holder);
 if ((self->flags >> 5) & 1) {
  self->a++;
  if (self->a==16) { self->a=0; self->flags &= ~0x20; }
  int kind=muMenu::exchangeGmCharacterKind2MuStockchkind(self->entries[0]);
  float frame=(float)(muMenu::exchangeGmCharacterKind2Something(kind)*10+1);
  if (self->holder) fn_8010CCE0(self->holder,self->a,self->values[self->b],self->c,frame);
 }
 if ((self->flags >> 4) & 1) {
  self->d++;
  if (self->d==10) {
   self->d=0; self->flags &= ~0x10;
   if (self->holder) fn_8010CA94(self->holder,self->count,self->entries);
  }
  if (self->d!=0 && self->d<10 && self->holder) fn_8010CC80(self->holder);
  if (self->holder) fn_8010CCA0(self->holder,self->d);
 }
 if (self->f68) {
  if (self->f68) {
   self->c64++;
   if (self->c64==1 && self->p60) fn_80108858(self->p60,1,0);
   if (self->c64==10) { self->c64=0; self->f68=0; }
  }
 }
 if (self->f6a) {
  if (self->f6a) {
   self->c66++;
   if (self->c66==1 && self->p60) fn_80108858(self->p60,0,0);
   if (self->c66==31) { self->c66=0; self->f6a=0; if (self->p60) fn_80108798(self->p60,0); }
  }
 }
 if (self->f69) {
  if (self->f69) {
   self->c65++;
   if (self->c65==1 && self->p60) fn_80108858(self->p60,1,1);
   if (self->c65==10) { self->c65=0; self->f69=0; }
  }
 }
 if (self->f6b) {
  if (self->f6b) {
   self->c67++;
   if (self->c67==1 && self->p60) fn_80108858(self->p60,0,1);
   if (self->c67==31) { self->c67=0; self->f6b=0; if (self->p60) fn_80108798(self->p60,1); }
  }
 }
}