#pragma force_active on
class Scene {
public:
 virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
 virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
 virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
 virtual void s38(); virtual void detach(void*);
};
struct Object { char pad[12]; void* model; void* resource; };
struct Menu {
 char pad0[0x50]; Scene* scene;
 Object* objects[109];
 char pad208[12]; Scene* otherScene;
 char pad218[0x2C]; int current; int pad248; int selected;
 char pad250[0x5E38]; float scroll;
 char pad608C[0xC0]; int base;
};
extern const float lbl_11_rodata_0[];
extern const float lbl_11_rodata_114[];
extern "C" {
 void setFrameVisible__8MuObjectFf(Object*,float);
 void fn_801AAFF0(void*,int);
 void fn_801AB014(void*,int);
 void fn_11_6384(Menu*,int);
 void fn_11_6130(Menu*,int);
}
inline void reset(Menu* self) {
 self->otherScene->detach(self->objects[108]->resource);
 for(int i=0;i<7;i++) {
  int value;
  Object* o=self->objects[i+93];
  if(o) {
   setFrameVisible__8MuObjectFf(o,lbl_11_rodata_0[0]);
   value=i+self->base+12;
   fn_801AAFF0(o->model,value);
   fn_801AB014(o->model,value);
  }
 }
}
inline void reset2(Menu* self) {
 self->otherScene->detach(self->objects[108]->resource);
 Object* o;
 int value;
 int i;
 for(i=0;i<7;i++) {
  o=self->objects[i+93];
  if(o) {
   setFrameVisible__8MuObjectFf(o,lbl_11_rodata_0[0]);
   value=i+self->base+12;
   fn_801AAFF0(o->model,value);
   fn_801AB014(o->model,value);
  }
 }
}
inline void highlight(Menu* self,int index) {
  int i=index-(int)self->scroll;
  if(i>=0 && i<7) {
   Object* o=self->objects[i+93];
   setFrameVisible__8MuObjectFf(o,lbl_11_rodata_114[0]);
   fn_801AAFF0(o->model,19);
   fn_801AB014(o->model,19);
  }
}
extern "C" void fn_11_5F24(Menu* self,int stage) {
 if(stage==self->current) return;
 int index;
 if(stage>=41 && stage<48) index=stage+(int)self->scroll-41;
 else index=-1;
 if(index>=0) {
  reset2(self);
  highlight(self,index);
 } else reset(self);
 if(index>=0) fn_11_6384(self,index);
 else if(stage!=0) fn_11_6130(self,stage);
 else self->scene->detach(self->objects[11]->resource);
 self->selected=index;
}
