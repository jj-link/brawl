#pragma force_active on
#include <so/so_value_accesser.h>
#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)
class Controller { public: V8(a) V8(b) virtual void x16(); virtual void x17(); virtual float getStickY(); virtual void x19(); virtual void x20(); virtual void x21(); virtual void x22(); virtual void x23(); virtual void x24(); virtual unsigned char getFlickY(); virtual void x26(); virtual void x27(); virtual void x28(); virtual void x29(); virtual void x30(); virtual void x31(); virtual void x32(); virtual void x33(); virtual void x34(); virtual void x35(); virtual void x36(); virtual void x37(); virtual unsigned button(); };
class Work { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual int getInt(unsigned); virtual void setInt(int,unsigned); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual float getFloat(unsigned); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual unsigned isFlag(unsigned); virtual void onFlag(unsigned); };
class Motion { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void setFrame(float); V8(b) virtual unsigned isEnd(); V8(c0) V8(c1) V8(c2) virtual void a41(); virtual void a42(); virtual void a43(); virtual void a44(); virtual int get(int); virtual void set(int,float); };
class Situation { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual int get(); };
class Sound { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void play(int,int,int,int); };
class Status { V32(a) public: virtual void b0(); virtual void b1(); virtual void change(int,soModuleAccesser*); };
class Article { V32(a) public: virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual int get(int); };
struct EffectVec { float x,y,z; };
class Effect { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void req(int,int,EffectVec*,EffectVec*,EffectVec*,EffectVec*,int,float,int); };
struct GroundBase { char pad[8]; };
class Ground : public GroundBase { public: V32(a) V32(b) V32(c) V8(d) virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual unsigned query(int); };
struct Modules { char pad0[8]; Motion* motion; void* pad0c; Ground* ground; Situation* situation; char pad18[0x50-0x18]; Sound* sound; char pad54[8]; Controller* controller; char pad60[4]; Work* work; char pad68[8]; Status* status; char pad74[0x88-0x74]; Effect* effect; char pad8c[0xa8-0x8c]; Article* article; };
struct Access { char pad[0xd8]; Modules* modules; };
extern "C" unsigned getButtonMask__12soControllerFQ212soController9PadButton(int);
extern "C" void fn_27_17DA90(void*,soModuleAccesser*,float);
extern "C" void fn_27_193378(soModuleAccesser*,float);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*,unsigned,unsigned);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*,unsigned,unsigned);
extern "C" const float lbl_27_rodata_2388[];
extern "C" void fn_27_17D558(void* self, soModuleAccesser* acc) {
 Access* a=(Access*)acc; const float* k=lbl_27_rodata_2388;
 switch(a->modules->work->getInt(0x2000000c)) {
 case 0: {
  EffectVec v[8];
  Controller* c=a->modules->controller; unsigned mask=getButtonMask__12soControllerFQ212soController9PadButton(0);
  unsigned btn=c->button(); if(btn & mask) {
   a->modules->work->setInt(1,0x2000000c);
   int status=a->modules->situation->get()==0?0xa4:0xad;
   if(a->modules->article->get(0)==0) {
    v[3].x=k[2]; v[3].y=k[2]; v[3].z=k[2];
    v[2].x=k[2]; v[2].y=k[2]; v[2].z=k[2];
    v[1].x=k[2]; v[1].y=k[2]; v[1].z=k[2];
    v[0].x=k[2]; v[0].y=k[2]; v[0].z=k[2];
    a->modules->effect->req(0x1a,0,&v[0],&v[1],&v[2],&v[3],0,k[3],0);
    a->modules->sound->play(0x1f56,0,0,0);
   } else {
    v[7].x=k[2]; v[7].y=k[2]; v[7].z=k[2];
    v[6].x=k[2]; v[6].y=k[2]; v[6].z=k[2];
    v[5].x=k[2]; v[5].y=k[2]; v[5].z=k[2];
    v[4].x=k[2]; v[4].y=k[2]; v[4].z=k[2];
    a->modules->effect->req(0x21,0,&v[4],&v[5],&v[6],&v[7],0,k[3],0);
   }
   a->modules->status->change(status,acc);
  }
  if(a->modules->situation->get()==0 && a->modules->ground->query(0)==1) {
   Controller* c=a->modules->controller; float limit=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc,0xc73,0);
   if(c->getStickY()<=limit) {
    Controller* c2=a->modules->controller; int n=getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(acc,0x5a65,0);
    if((int)c2->getFlickY()<n)a->modules->work->onFlag(0x22000011);
   }
  }
  break;
 }
 case 1:
  if(a->modules->motion->isEnd()==1) {
   if(a->modules->motion->get(1)!=-1)a->modules->motion->set(1,k[2]); else a->modules->motion->setFrame(k[2]);
   a->modules->work->setInt(0,0x2000000c);
   int status=a->modules->situation->get()==0?0xa4:0xad;
   a->modules->status->change(status,acc);
  } else if(a->modules->work->isFlag(0x22000013)==1 && a->modules->situation->get()==2) {
   fn_27_193378(acc,a->modules->work->getFloat(0x21000008)-k[4]);
  } else fn_27_17DA90(self,acc,k[2]);
  break;
 }
}
